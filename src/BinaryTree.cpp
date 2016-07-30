//============================================================================
// Name        : BinaryTree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node {
	int key;
	node* left;
	node* right;
};

typedef struct node NODE;

NODE* createNode(int x) {
	NODE* n = (NODE*) malloc(sizeof(NODE));
	n->key = x;
	n->left = NULL;
	n->right = NULL;
	return n;
}

NODE* searchNodeRecusive(NODE* root, int x) {
	if (root == NULL) {
		return NULL;
	}
	if (root->key == x) {
		return root;
	} else if (root->key > x) {
		return searchNodeRecusive(root->left, x);
	} else if (root->key < x) {
		return searchNodeRecusive(root->right, x);
	}
	return NULL;
}

NODE* searchNode(NODE* root, int x) {
	if (root == NULL) {
		return NULL;
	}
	NODE* p = root;
	while (p != NULL) {
		if (p->key == x) {
			return p;
		} else if (p->key > x) {
			p = p->left;
		} else if (p->key < x) {
			p = p->right;
		}
	}
	return NULL;
}

NODE* findInsert(NODE* root, int x) {
	if (root == NULL) {
		return NULL;
	}
	NODE* p = root;
	NODE* f;
	while (p != NULL) {
		f = p;
		if (p->key > x) {
			p = p->left;
		} else if (p->key < x) {
			p = p->right;
		}
	}
	return f;
}

void insertNode(NODE* &root, int x) {
	NODE* n = createNode(x);
	if (root == NULL) {
		root = n;
		return;
	}
	NODE* f = findInsert(root, x);
	if (f != NULL) {
		if (f->key > x) {
			f->left = n;
			cout << x << " insert into left of " << f->key << endl;
		} else if (f->key < x) {
			f->right = n;
			cout << x << " insert into right of " << f->key << endl;
		}
	}
}

void NLR(NODE* root) {
	if (root != NULL) {
		cout << root->key << "\t";
		NLR(root->left);
		NLR(root->right);
	}
}

void LNR(NODE* root) {
	if (root != NULL) {
		LNR(root->left);
		cout << root->key << "\t";
		LNR(root->right);
	}
}

void RNL(NODE* root) {
	if (root != NULL) {
		RNL(root->right);
		cout << root->key << "\t";
		RNL(root->left);
	}
}

void createTree(NODE* &root, int a[], int n) {

	for (int i = 0; i < n; i++) {
		insertNode(root, a[i]);
	}

}

int main() {
	NODE* root = NULL;
	int a[] = {43, 56, 21, 31, 9, 35, 10, 15, 19, 62, 65};
	int n = 11;
	createTree(root, a, n);
	NLR(root);
	cout << endl;
	LNR(root);
	cout << endl;
	RNL(root);
	cout << endl;
	NODE* searchR = searchNode(root, 21);
	if (searchR != NULL) {
		cout << "Search found " << searchR->key << endl;
		if (searchR->left != NULL) {
			cout << "Search found left " << searchR->left->key << endl;
		}
		if (searchR->right != NULL) {
			cout << "Search found right " << searchR->right->key << endl;
		}
	}

	return 0;
}
