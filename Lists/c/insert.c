#include<stdio.h>
#include<stdlib.h>
#include "list.h"

void push(Node** head_ref, int data)
{
	Node* new_node = malloc(sizeof(Node));
	if(!new_node)
		fprintf(stderr, "malloc failed in push");
	new_node -> data = data;
	new_node -> next = *head_ref;
	*head_ref = new_node;
}

void append_rear(Node** head_ref, int data)
{
	Node* current = *head_ref;
	if(!current)
		push(head_ref, data);
	else
	{
		while(current -> next)
			current = current -> next;
		push(&(current -> next), data);
	}
}

void print_list(Node* head)
{
	Node* current = head;
	while(current)
	{
		printf("%d-> ", current -> data);
		current = current -> next;
	}
	printf("NULL\n");
}

int main()
{
	Node* head = malloc(sizeof(Node));
	Node* second = malloc(sizeof(Node));
	
	head -> data = 1;
	head -> next = second;
	
	second -> data = 2;
	second -> next = NULL;
	
	print_list(head);
	
	push(&head, 0);
	push(&head, -1);
	append_rear(&head, 3);
	append_rear(&head, 4);
	
	print_list(head);
	return 0;
}
