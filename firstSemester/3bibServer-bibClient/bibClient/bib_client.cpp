#include "bib_client.h"
#include <cstdio>


Client::Client(int port, char* server_addr) {
	this->error_code = 0;
	this->port = port;
	strncpy(this->server_addr, server_addr, MAX_LENGTH);
}

int Client::setup_connection() {
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

    (this->dest_addr).sin_family=AF_INET;
    (this->dest_addr).sin_port=htons(port);
 
	HOSTENT *hst;

	if (inet_addr(this->server_addr) != INADDR_NONE) {
      (this->dest_addr).sin_addr.s_addr=inet_addr(this->server_addr);
	}
    else
    if (hst=gethostbyname(this->server_addr)) {
		((unsigned long *)&(this->dest_addr).sin_addr)[0] = ((unsigned long **)hst->h_addr_list)[0][0];
	}
    else {
		printf("Invalid address %s\n", this->server_addr);
		closesocket(this->sock);
		WSACleanup();
		this->error_code = -1;
		return -1;
    }

	if (connect(this->sock,(sockaddr *)&(this->dest_addr), sizeof(this->dest_addr))) {
		printf("Connect error %d\n",WSAGetLastError());
		this->error_code = -1;
		return -1;
    }

	printf("Connecting with %s set successfully\n\n", this->server_addr);
	return 0;
}

void Client::send_data(char* file_path) {
	char buff_s[MAX_LENGTH];
	sprintf_s(buff_s, "%s\n", file_path);
	printf("%s",buff_s);

	int buff_size = strlen(buff_s);

	send(sock, buff_s, buff_size, 0);
	char buff_r[MAX_LENGTH];
	while((buff_size = recv(sock, &(buff_r[0]), MAX_LENGTH, 0)) != SOCKET_ERROR) {
		char *p;
		p = strchr(buff_r, '#');
			*p = 0;
			printf("%s\n",buff_r);
	}
			closesocket(sock);
			WSACleanup();
	return;
}
