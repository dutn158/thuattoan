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

void insertFirst(NODE* &head, int x) {
	NODE* n = createNode(x);
	n->next = head;
	head = n;
}

NODE* findParent(NODE* head, int x) {
	if (head == NULL) {
		return NULL;
	}
	if (head->next != NULL) {
		if (head->next->key == x) {
			return head;
		}
		return findParent(head->next, x);
	}
	return NULL;
}

NODE* findNode(NODE* head, int x) {
	if (head == NULL) {
		return NULL;
	}
	if (head->key == x) {
		return head;
	} else {
		return findNode(head->next, x);
	}
	return NULL;
}

void deleteNode(NODE* &head, int x) {
	NODE* parent = findParent(head, x);
	if (parent == NULL) {
		NODE* f = head;
		head = head->next;
		delete(f);
	} else {
		NODE* n = findNode(head, x);
		parent->next = n->next;
		delete(n);
	}
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

void findMiddleLinkedList(NODE* head, NODE* head2) {
	NODE* f = head;
	NODE* f2 = head2;

	if  (f2 == NULL) {
		cout << "Middle is " << f->key << endl;
	}
	findMiddleLinkedList(head->next, head2->next->next);

}

int main(int argc, char **argv) {
	NODE* head = NULL;
	int a[] = {14, 16, 31, 26, 9, 5, 29, 51, 43, 10};
	int n = 10;
	createLinkedList(head, a, n);
	insertFirst(head, 90);
//	deleteNode(head, 10);
	insertNode(head, 120);
	printLinkedList(head);
	cout << endl;

	findMiddleLinkedList(head, head->next->next);

	int f = 9;
	cout << "Parent of "<< f << " is " << findParent(head, f)->key;
	cout << endl;
	return 0;
}



