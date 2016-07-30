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

NODE* findParent(NODE* root, int x) {
	if (root->left != NULL) {
		if (root->left->key == x) {
			return root;
		}
	}
	if (root->right != NULL) {
		if (root->right->key == x) {
			return root;
		}
	}
	if (root->key > x) {
		return findParent(root->left, x);
	} else {
		return findParent(root->right, x);
	}
}

NODE* findParent(NODE* root, NODE* n) {
	return findParent(root, n->key);
}

NODE* findNode(NODE* root, int x) {
	if (root->key == x) {
		return root;
	}
	if (root->key > x) {
		return findNode(root->left, x);
	} else {
		return findNode(root->right, x);
	}
}

NODE* findMin(NODE* del) {
	if (del == NULL) {
		return NULL;
	}
	if (del->left != NULL) {
		return findMin(del->left);
	}
	return del;
}

void deleteNode(NODE* &root, int x) {
	if (root == NULL) {
		return;
	}
	NODE* del = findNode(root, x);
	if (del->left == NULL && del->right == NULL) {
		NODE* p = findParent(root, del);
		if (p->key > x) {
			p->left = NULL;
		} else if (p->key < x) {
			p->right = NULL;
		}
		delete(del);
		return;
	} else if (del->left != NULL && del->right != NULL) {
		NODE* min = findMin(del->right);
		NODE* p = findParent(root, del);
		min->left = del->left;
		p->left = min;
		if (p->key > del->right->key) {
			p->left = del->right;
		} else if (p->key < del->right->key) {
			p->right = del->right;
		}
		delete(del);
	} else {
		NODE* temp = del;
		NODE* p = findParent(root, del);
		if (del->left != NULL) {
			del = del->left;
		} else if (del->right != NULL) {
			del = del->right;
		}
		if (p->key > del->key) {
			p->left = del;
		} else if (p->key < del->key) {
			p->right = del;
		}
		delete(temp);
		return;
	}

}

int main() {
	NODE* root = NULL;
	int a[] = {43, 56, 21, 31, 9, 35, 10, 15, 19, 62, 65};
	int n = 11;
	createTree(root, a, n);

	deleteNode(root, 21);

	NLR(root);
	cout << endl;
	LNR(root);
	cout << endl;
	RNL(root);
	cout << endl;
//	NODE* searchR = searchNode(root, 21);
//	if (searchR != NULL) {
//		cout << "Search found " << searchR->key << endl;
//		if (searchR->left != NULL) {
//			cout << "Search found left " << searchR->left->key << endl;
//		}
//		if (searchR->right != NULL) {
//			cout << "Search found right " << searchR->right->key << endl;
//		}
//	}
//
//	int d = 15;
//	NODE* parent = findParent(root, d);
//	cout << "Parent of " << d << " is " << parent->key;
//
//	cout << endl << endl;
//
//	NODE* find = findNode(root, 62);
//	NODE* fp = findParent(root, find);
//	cout << "Parent of " << find->key << " is " << fp->key;
	return 0;
}
