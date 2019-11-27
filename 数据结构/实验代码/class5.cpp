#include<iostream>
using namespace std;
typedef struct BiNode {
	int data;
	struct BiNode *lchild;
	struct BiNode *rchild;
} BiNode, *BiTree;

bool search(BiTree tree, int key) {
	if (tree == NULL) {
		return false;
	}
	else if (tree->data == key) {
		return true;
	}
	else if (tree->data > key) {
		return search(tree->lchild, key);
	}
	else {
		return search(tree->rchild, key);
	}
}

void insert(BiTree &T, int key) {
	if (!T) {
		T = new BiNode;
		T->data = key;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else if (key < T->data) {
		insert(T->lchild, key);
	}
	else if (key > T->data) {
		insert(T->rchild, key);
	}
}
void inOrder(BiTree T) {
	if (T)
	{
		inOrder(T->lchild);
		cout << T->data;
		inOrder(T->rchild);
	}
	else
		cout << " ";
}
BiTree Find_min(BiTree tree) {
	if (!tree) return NULL;
	else if (!tree->lchild) return tree;
	else return Find_min(tree->lchild);
}
void Delete(BiTree &tree, int key) {
	if (!tree) return;
	else if (key < tree->data) {
		Delete(tree->lchild, key);
	}
	else if (key > tree->data) {
		Delete(tree->rchild,key);
	}
	else{
		if (tree->lchild && tree->rchild) {
			BiTree temp = Find_min(tree->rchild);
			tree->data = temp->data;
			Delete(tree->rchild, temp->data);
		}
		else {
			if (!tree->lchild) tree = tree->rchild;
			else if (!tree->rchild) tree = tree->lchild;
		}
	}
}
int NumOfSon(BiTree tree) {
	if (tree == NULL) {
		return 0;
	}
	else if (tree->lchild == NULL && tree->rchild == NULL) {
		return 1;
	}
	else
	{
		int left = NumOfSon(tree->lchild);
		int right = NumOfSon(tree->rchild);
		return left + right;
	}
}

int main() {
	int a[] = { 62,88,58,47,35,73,51,99,37,93 };
	BiTree tree = NULL;
	for (int i = 0; i < 10; i++) {
		insert(tree, a[i]);
	}
	inOrder(tree);
	cout <<endl<< "���ҽ��(1��ʾ�ҵ�0��ʾδ�ҵ�):"<<search(tree, 51) << endl;;
	cout << "Ҷ�ӽ������" <<NumOfSon(tree);
	Delete(tree, 35);
	cout << "ɾ��35����������:" << endl;
	inOrder(tree);
	return 0;
}