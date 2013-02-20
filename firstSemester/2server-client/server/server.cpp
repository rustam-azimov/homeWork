#include "server.h"
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
	    SOCKET client_socket;    // сокет для клиента
    sockaddr_in client_addr;    // адрес клиента
              // (заполняется системой)

    // функции accept необходимо передать размер
    // структуры
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
    while( (bytes_recv = recv(my_sock, &buff[0], sizeof(buff), 0))&& bytes_recv !=SOCKET_ERROR) {
		buff[bytes_recv] = 0;
		printf("%s\n", buff);
		char* fname;
		fname = strchr(buff, '/');
		*fname = 0;
		fname++;
		char* p;
		p = strchr( fname, ' ');
		*p = 0;
		p++;
		printf("%s %d\n", fname,bytes_recv);
		FILE* server_file;
		server_file = fopen(fname, "r");
		if (server_file == 0) {
			printf("File not found!\n");
			send(my_sock,"Cannot open the file!\n", 30, 0);
			return 0;
		}
		char file_string[64];
		while (fgets(file_string,64, server_file)) {
			printf("%s\n", file_string);
			send(my_sock, &(file_string[0]), sizeof(file_string), 0);
		}
		fclose(server_file);
	}

    nclients--;
	printf("-disconnect\n\n\n"); 
    closesocket(my_sock);
    return 1;
  }