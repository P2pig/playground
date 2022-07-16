#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
//定义链表结构
struct Node{
	DataType data;
	struct Node *next;
};
typedef struct Node node;
//定义头尾指针
struct head_tail{
	node* front;
	node* rear;
};
struct head_tail *p;


void init(){
	p->front = (node*)malloc(sizeof(node));
	p->front->next = NULL;
	p->rear  = p->front;
}

void insert(char data){
	p->rear->next = (node*)malloc(sizeof(node));
	p->rear = p->rear->next;
	p->rear->data = data;
	p->rear->next = NULL;
}

void out(char* data){
	if(p->front==p->rear)
		return;
	node* temp;
	temp=p->front->next;
	p->front->next = temp->next;
	*data=temp->data;
	if(p->rear == temp)
		p->rear=p->front;
	free(temp);

}
void main(){
	char c;
	init();
	while(1){
		scanf("%c",&c);
		if(c=='#')
			break;
		insert(c);
	}
	while(p->front!=p->rear){
		out(&c);
		printf("%c",c);
	}	

}
