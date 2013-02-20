#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <winsock2.h>  
#include <windows.h>

#pragma comment(lib,"Ws2_32.lib")

// прототип функции, обслуживающий
// подключившихся пользователей
DWORD WINAPI ServeClient(LPVOID client_socket);

static int nclients = 0;
const static int MAX_SIZE = 1024;

class Server {
	private:
		char buff[MAX_SIZE];
		int port;
		//sockaddr_in client_addr;
		SOCKET sock;
		sockaddr_in local_addr;
		int error_code;
		
	public:
		Server(int port);
		int setup_connection();
		void recv_data();

};

#endif