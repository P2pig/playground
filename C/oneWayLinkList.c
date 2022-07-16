#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	int b;
	struct Node *next;
};
typedef struct Node node;

void func1() {
	node head = {.value = 100};
	node new1 = {.value = 200};
	head.next = &new1;

	node *current = &head;
	while(current != NULL) 
	{
		printf("current: %d", current->value);	
		current = current->next;
	}
}

void func2() {
	node *head = (node *) malloc(sizeof(node));
	node *new1 = (node *) malloc(sizeof(node));
	head->next = new1;
	head->value = 100;
	new1->value = 200;

	node *current = head;
	while(current != NULL) 
	{
		printf("current: %d\n", current->value);	
		current = current->next;
	}
}

int main(int argc, char *argv[]) {
	func2();


	return 0;
}
