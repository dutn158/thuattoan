/*
 * LinkedList.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: TranDu
 */

#include <iostream>
using namespace std;

struct node {
	int key;
	node* next;
};

typedef struct node NODE;

NODE* createNode(int x) {
	NODE* n = (NODE*) malloc(sizeof(NODE));
	n->key = x;
	n->next = NULL;
	return n;
}

NODE* findInsert(NODE* head) {
	if (head->next == NULL) {
		return head;
	}
	return findInsert(head->next);
}

void insertNode(NODE* &head, int x) {
	NODE* n = createNode(x);
	if (head == NULL) {
		head = n;
		cout << "Head == NULL, Head = n" << endl;
		return;
	}
	NODE* f = findInsert(head);
	cout << "Found f " << f->key << endl;
	f->next = n;
}

void createLinkedList(NODE* &head, int a[], int n) {
	for (int i = 0; i < n; i++) {
		insertNode(head, a[i]);
	}
}

void printLinkedList(NODE* head) {
	NODE* p = head;
	if (p != NULL) {
		cout << p->key << "\t";
		if (p->next == NULL) {
			return;
		}
		printLinkedList(p->next);
	}
}

int main(int argc, char **argv) {
	NODE* head = NULL;
	int a[] = {14, 16, 31, 26, 9, 5, 29, 51, 43, 10};
	int n = 10;
	createLinkedList(head, a, n);
	printLinkedList(head);
	cout << endl;
	return 0;
}



