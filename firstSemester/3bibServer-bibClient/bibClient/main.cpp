#include "bib_client.h"
#include <cstdio>

int main() {
	Client client(1111, "127.0.0.1");
	client.setup_connection();
	char find[80];
	char param[80];
	char name[80];
	scanf("%s",&find[0]);
	scanf("%s",&param[0]);
	scanf("%s",&name[0]);
	char* enter;
	enter = (char*)malloc(sizeof(char*));
	sprintf(enter,"%s %s %s", &find[0], &param[0], &name[0]);
	printf("\n");
	client.send_data(enter);
	getchar();
	return 0;
}