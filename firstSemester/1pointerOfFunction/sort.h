#ifndef _SORT_H_
#define _SORT_H_

const static int MAX_LENGTH = 80;

struct Node {
       char name[MAX_LENGTH];
       int id;
	   char password[MAX_LENGTH];
	   char fullname[MAX_LENGTH];
       Node *next;
};
Node* add_node(Node *head, char *name, int id, char *password, char *fullname);
int sort_name(Node *elem1, Node* elem2);
int sort_id(Node *elem1, Node* elem2);
int sort_fullname(Node *elem1, Node* elem2);
Node* sort_main(Node* head, int (*pf)(Node *elem1, Node* elem2));
void print_node(Node* head);
void print_choose();
void swap( Node* elem1, Node* elem2);
#endif