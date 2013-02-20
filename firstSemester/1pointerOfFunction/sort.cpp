#include "sort.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

Node* make_node(Node *head) {
    head = (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;
    return head;
}

Node* add_node(Node *head, char *name, int id, char *password, char *fullname) {
    if (head == NULL) {
        head = make_node(head);
        strncpy(head->name, name, 80);
		head->id = id;
        strncpy(head->password, password, 80);
		strncpy(head->fullname, fullname, 80);
        return head;
    }     
    head->next = add_node(head->next, name, id, password, fullname);
	return head;
}

int sort_name(Node *elem1, Node* elem2) {
	if (strcmp(elem1->name, elem2->name) > 0)
        return 1;
    else
        return -1;
}

int sort_id(Node *elem1, Node* elem2) {
	if (elem1->id > elem2->id)
        return 1;
    else
        return -1;
}

int sort_fullname(Node *elem1, Node* elem2) {
	if (strcmp(elem1->fullname, elem2->fullname) > 0)
        return 1;
    else 
        return -1;
}

Node* sort_main(Node* head, int (*pf)(Node *elem1, Node* elem2)) {
	for ( Node* curr_i = head; curr_i; curr_i = curr_i->next) {
		for ( Node* curr_j = head; curr_j; curr_j = curr_j->next) {
			if (pf(curr_i, curr_j) < 0) {
				swap(curr_i, curr_j);
			}
		}
	}
	return head;
}

void swap_string(char *a, char *b) {
	char *tmp;
	tmp = (char*)malloc(MAX_LENGTH);
	tmp = strncpy(tmp, a, MAX_LENGTH);
	a = strncpy(a, b, MAX_LENGTH);
	b = strncpy(b, tmp, MAX_LENGTH);

	free(tmp);
}

void swap( Node* elem1, Node* elem2) {
	swap_string(elem1->name, elem2->name);
	swap_string(elem1->fullname, elem2->fullname);
	swap_string(elem1->password, elem2->password);
	int tmp = elem1->id;
	elem1->id = elem2->id;
	elem2->id = tmp;	
}
void print_node(Node* head) {
    Node* temp;
    temp = head;
    while (temp) {
        printf("%s, %d, %s, %s\n", temp->name, temp->id, temp->password, temp->fullname);
        temp = temp->next;
    }
    printf("\n");
    printf("\n");

}
void print_choose() {
    printf("Enter your choose: ");
    printf("1 - name; ");
    printf("2 - id; ");
    printf("3 - fullname; ");
    printf("0 - exit.\n");
}
