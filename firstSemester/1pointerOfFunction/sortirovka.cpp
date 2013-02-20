#include "sort.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
	Node* list = NULL;
    FILE * treeFile;
    treeFile = fopen("fileToSort.txt" , "r");
    if (treeFile == NULL)
    {
     printf("Cannot open the file!\n");
     getchar();
     return 0;
    }
    char *name;
    while(!feof(treeFile))
    {	name = (char*)malloc(250);
		fgets (name, 250, treeFile);
		char *idstr = strchr(name, ':');
		*idstr = 0;
		idstr++;
		char *password = strchr(idstr, ':');
		*password = 0;
		password++;
		char *fullname = strchr(password , ':');
		*fullname = 0;
		fullname++;
		int id;
		id = atoi(idstr);
		list = add_node(list, name, id, password, fullname);
    }
    fclose(treeFile);
	int (*psort_name)(Node* elem1, Node* elem2);
	psort_name = &sort_name;
	int (*psort_id)(Node* elem1, Node* elem2);
	psort_id = &sort_id;
	int (*psort_fullname)(Node* elem1, Node* elem2);
	psort_fullname = &sort_fullname;
    print_node(list);
    int param = -1;
    while (param) {
        print_choose();
        scanf("%d", &param);
        if (param == 1) {
            list = sort_main(list, psort_name);
			print_node(list);
        } else if (param == 2) {
            list = sort_main(list, psort_id);
			print_node(list);
        } else if (param == 3) {
            list = sort_main(list, psort_fullname);
			print_node(list);
        }
    }
    getchar();
	return 0;
}
