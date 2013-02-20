#ifndef BIB_CLIENT_H
#define BIB_CLIENT_H

#include <winsock2.h>
#include <windows.h>
#pragma comment(lib,"Ws2_32.lib")

const static int MAX_BITS = 1024;
const static int MAX_LENGTH = 64;

class Client {
	private:
		char buff [MAX_BITS];
		char buff_s [MAX_BITS];
		int port;
		char server_addr[MAX_LENGTH];
		SOCKET sock;
		sockaddr_in dest_addr;
		int error_code;

	public:
		Client(int port, char* server_addr);
		int setup_connection();
		void send_data(char*);

};

#endif