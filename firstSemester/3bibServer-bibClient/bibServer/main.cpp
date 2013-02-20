#include "bib_server.h"
#include <cstdio>

int main() {
	Server server(1111);
	server.setup_connection();
	server.recv_data();
}