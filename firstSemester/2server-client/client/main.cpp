#include "client.h"
#include <cstdio>

int main() {
	char enter[80];
	scanf("%s",&enter[0]);
	char *host;
	host = strchr(&enter[0], '/');
	host = host + 2;
	char *path;
	path = strchr(host,'/');
	*path = 0;
	path++;
	Client client(1111, host);
	client.setup_connection();
	client.send_data(path);
	getchar();
	return 0;
}