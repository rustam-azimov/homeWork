#ifndef BIB_SERVER_H
#define BIB_SERVER_H

#include <stdio.h>
#include <winsock2.h>  
#include <windows.h>

#pragma comment(lib,"Ws2_32.lib")

DWORD WINAPI ServeClient(LPVOID client_socket);

static int nclients = 0;
const static int MAX_SIZE = 1024;

class Server {
	private:
		char buff[MAX_SIZE];
		int port;
		SOCKET sock;
		sockaddr_in local_addr;
		int error_code;
		
	public:
		struct Node {
			int code;
			char *author;
			char *book;
			int year;
			char *status;
			Node *right;
};
		
		Server(int port);
		int setup_connection();
		void recv_data();

};
struct Node {
			char *code;
			char *author;
			char *book;
			char *year;
			char *status;
			char *full;
			Node *right;
};
Node* make_node(Node *head);
Node* add_node(Node *head, char *code, char *author, char *book, char *year, char *status);
bool cmp_author(Node *elem, char* author);
bool cmp_book(Node *elem, char* book);
void find_main(Node* head, char* find_item, bool (*pf)(Node *elem, char* find_item), SOCKET my_sock);
#endif