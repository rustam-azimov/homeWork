#include "bib_server.h"
#include <cstdio>

Server::Server(int port) {
	this->error_code = 0;
	nclients = 0;
	this->port = port;
}

int Server::setup_connection() {
	if (WSAStartup(0x202,(WSADATA *)&(this->buff)[0])) {
		this->error_code = WSAGetLastError();
		printf("WSAStart error %d\n",WSAGetLastError());
		return WSAGetLastError();
    }
	if ((this->sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		this->error_code = WSAGetLastError();
		printf("Socket() error %d\n",WSAGetLastError());
		return WSAGetLastError();
	}
	(this->local_addr).sin_family=AF_INET;
    (this->local_addr).sin_port=htons(port);
    (this->local_addr).sin_addr.s_addr=0;
	 if (bind(this->sock,(sockaddr *) &(this->local_addr),sizeof(this->local_addr)))
    {
      	printf("Error bind %d\n",WSAGetLastError());
		this->error_code = -1;
		return -1;
    }
	 if (listen(this->sock, 0x100))
    {
      printf("Error listen %d\n",WSAGetLastError());
      closesocket(this->sock);
      WSACleanup();
	  this->error_code = -1;
      return -1;
    }
	 printf("Waiting for connections\n\n");
	 return 0;
}
void Server::recv_data() {
	    SOCKET client_socket;    
    sockaddr_in client_addr;    

    int client_addr_size=sizeof(client_addr);
	
    while((client_socket = accept(this->sock, (sockaddr *)&client_addr, &client_addr_size)))
    {
      nclients++;
      HOSTENT *hst;
      hst = gethostbyaddr((char *)&client_addr.sin_addr.s_addr,4, AF_INET);

      printf("+%s [%s] new connect!\n",(hst)?hst->h_name:"",inet_ntoa(((client_addr).sin_addr)));

      DWORD thID;
      CreateThread(NULL,NULL,ServeClient,&client_socket,NULL,&thID);
    }
    return;
  }

  DWORD WINAPI ServeClient(LPVOID client_socket)
  {
	SOCKET my_sock;
    my_sock=((SOCKET *) client_socket)[0];
    char buff[20*MAX_SIZE];
	int bytes_recv;
	FILE* server_file;
	server_file = fopen("bib.txt", "r");
	if (server_file == 0) {
		printf("File not found!\n");
		send(my_sock,"Cannot open the file!\n", 30, 0);
		return 0;
	}
    while( (bytes_recv = recv(my_sock, &buff[0], sizeof(buff), 0))&& bytes_recv !=SOCKET_ERROR) {
		buff[bytes_recv] = 0;
		printf("%s\n", buff);
		char file_string[64];
		Node* head;
		head = NULL;
		while (fgets(file_string, 64, server_file)) {
			char* author;
			author = strchr(file_string, ';');
			*author = 0;
			author++;
			char* book;
			book = strchr(author, ';');
			*book = 0;
			book++;
			char* year;
			year = strchr(book, ';');
			*year = 0;
			year++;
			char* status;
			status = strchr(year, ';');
			*status = 0;
			status++;
			head = add_node(head, file_string, author, book, year, status);
		}
		fclose(server_file);
		char *param = strchr(buff, ' ');
		*param = 0;
		param++;
		char *find_item = strchr(param, ' ');
		*find_item = 0;
		find_item++;
		char* p = strchr(find_item, '\n');
		*p = 0;
		p++;
		bool (*pcmp)(Node *elem, char* author);
		if(strcmp("author", param) == 0) {
			pcmp = &cmp_author;
		} else {
			pcmp = &cmp_book;
		}
		find_main(head, find_item, pcmp, my_sock);
				
	}

    nclients--;
	printf("-disconnect\n\n\n"); 
    closesocket(my_sock);
    return 1;
  }

  Node* make_node(Node *head) {
    head = (struct Node*)malloc( sizeof( struct Node ) );
    head->right = NULL;
    return head;
}

  Node* add_node(Node *head, char* code, char *author, char *book, char* year, char* status) {
    if (head == NULL) {
        head = make_node(head);
		head->code = (char*)malloc(sizeof(code));
		head->author = (char*)malloc(sizeof(char*));
		head->book = (char*)malloc(sizeof(char*));
		head->year = (char*)malloc(sizeof(char*));
		head->status = (char*)malloc(sizeof(char*));
        strncpy(head->code, code, strlen(code));
        strncpy(head->author, author, strlen(author));
		strncpy(head->book, book, strlen(book));
		strncpy(head->year, year,strlen(year));
		strncpy(head->status, status, strlen(status));
		head->code[strlen(code)] = 0;
		head->author[strlen(author)] = 0;
		head->book[strlen(book)] = 0;
		head->year[strlen(year)] = 0;
		head->status[strlen(status)] = 0;
        return head;
    }  

    head->right = add_node(head->right, code, author, book, year, status);
    return head;
}

   bool cmp_author(Node *elem, char* author) {
	   int i, j;
	  bool result;
	  result = false;
	  int size_author, size_elem;
	  size_author = strlen(author);
	  size_elem = strlen(elem->author);
	  if (strcmp(author, "*") == 0) {
		  result = true;
	  } else if((author[0] == '*')&&(author[size_author - 1] == '*')) {
			  for(i = 0; i < size_elem; i++) {
			  for(j = 1; j < size_author - 1; j++) {
				  if (elem->author[i+j-1] != author[j]) {
					  j = size_author + 1;
				  }
			  }
			  if (j == size_author - 1) {
				  result = true;
			  }
		  }
	  } else if(author[0] == '*') {
		  i = size_elem - size_author;
		  if ( i >= -1) {
			  for ( j = 1; j < size_author; j++) {
				  if ( elem->author[i + j] != author[j]) {
					  j = size_author + 1;
				  }
			  }
			  if (j == size_author) {
					  result = true;
				  }
		  }
	  } else if (author[size_author - 1] == '*') {
		  j = size_elem - size_author;
		  if ( j >= -1) {
			  for ( i = 0; i < size_author - 1; i++) {
				  if (elem->author[i] != author[i]) {
					  i = size_author + 1;
				  }
			  }
			  if( i == size_author - 1) {
					  result = true;
				  }
		  }
	  } else {
		  if (size_elem == size_author) {
			  for (i = 0; i < size_author; i++) {
				  if (elem->author[i] != author[i]) {
					  i = size_author + 1;
				  }
			  }
			  if (i == size_author) {
					  result = true;
				  }
		  }
	  }
	  return result;
  }

  bool cmp_book(Node *elem, char* book) {
	   int i, j;
	  bool result;
	  result = false;
	  int size_book, size_elem;
	  size_book = strlen(book);
	  size_elem = strlen(elem->book);
	  if (strcmp(book, "*") == 0) {
		  result = true;
	  } else if((book[0] == '*')&&(book[size_book-1] == '*')) {
			  for(i = 0; i < size_elem; i++) {
			  for(j = 1; j < size_book - 1; j++) {
				  if (elem->book[i+j-1] != book[j]) {
					  j = size_book + 1;
				  }
			  }
			  if (j == size_book - 1) {
				  result = true;
			  }
		  }
	  } else if(book[0] == '*') {
		  i = size_elem - size_book;
		  if ( i >= -1) {
			  for ( j = 1; j < size_book; j++) {
				  if ( elem->book[i + j] != book[j]) {
					  j = size_book + 1;
				  }
			  }
			  if (j == size_book) {
					  result = true;
				  }
		  }
	  } else if (book[size_book - 1] == '*') {
		  j = size_elem - size_book;
		  if ( j >= -1) {
			  for ( i = 0; i < size_book - 1; i++) {
				  if (elem->book[i] != book[i]) {
					  i = size_book + 1;
				  }
			  }
			  if( i == size_book - 1) {
					  result = true;
				  }
		  }
	  } else {
		  if (size_elem == size_book) {
			  for (i = 0; i < size_book; i++) {
				  if (elem->book[i] != book[i]) {
					  i = size_book + 1;
				  }
				  if (i == size_book) {
					  result = true;
				  }
			  }
		  }
	  }
	  return result;
  }

  void find_main(Node* head, char* find_item, bool (*pf)(Node *elem, char* find_item), SOCKET my_sock) {
	  Node* temp;
	  char sender[MAX_SIZE];
	  temp = head;
	  char send_string[MAX_SIZE];
	  while(temp) {
		  if (pf(temp, find_item)){
			  sprintf(send_string,"%s ; %s ; %s ; %s ; %s#", temp->code, temp->author, temp->book, temp->year, temp->status);
			  send(my_sock, send_string, 64, 0);
		  }
		  temp = temp->right;
	  }
  }