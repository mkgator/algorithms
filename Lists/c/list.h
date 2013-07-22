#ifndef LIST_H_
#define LIST_H_

typedef struct node{
	int data;
	struct node* next;
}Node;

void push(Node** head_ref, int data);

void print_list(Node* head);

#endif	/* LIST_H_ */
