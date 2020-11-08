#include <stdio.h>
#include <stdlib.h>
struct n {
	int x;
	struct	n* next;
};
typedef struct n node;
//Baðlý Listeler

void toPrint(node* r) {
	while (r != NULL)
	{
		printf("%d ", r->x);
		r = r->next;
	}
}
void Add(node* r, int x) {
	while (r->next != NULL)
	{
		r = r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;
}
int main() {
	node* root;
	//malloc void * döndürdüðü için node'e cast ediyoruz.
	root = (node*)malloc(sizeof(node)); //1.düðüm
	root->next = NULL;
	root->x = -10;//1.data

	int i = 0;
	for (i = 0; i < 5; i++)
	{
		Add(root, i * 10);
		//iter->next = (node*)malloc(sizeof(node));//Yeni bir düðüm ekliyoruz
		//iter = iter->next;//iter'in next'ini göstersin
		//iter->x = i * 10;
		//iter->next = NULL;
	}
	toPrint(root);
}
void LinkedList1() {
	node* root;
	//malloc void * döndürdüðü için node'e cast ediyoruz.
	root = (node*)malloc(sizeof(node)); //1.düðüm
	root->x = 10;//1.data

	root->next = (node*)malloc(sizeof(node));//2.düðüm
	root->next->x = 20;//2.data

	root->next->next = (node*)malloc(sizeof(node));//3.düðüm
	root->next->next->x = 30; //3.data

	root->next->next->next = NULL;//4.düðüm
	node* iter;
	iter = root;
	printf("%d \n", iter->x);

	iter = iter->next;
	printf("%d \n", iter->x);

	iter = root;
	int i = 0;
	while (iter->next != NULL)
	{
		i++;
		printf("%d. eleman : %d \n", i, iter->x);
		iter = iter->next;
	}

	for (i = 0; i < 5; i++)
	{
		iter->next = (node*)malloc(sizeof(node));//Yeni bir düðüm ekliyoruz
		iter = iter->next;//iter'in next'ini göstersin
		iter->x = i * 10;
		iter->next = NULL;
	}
	toPrint(root);
}