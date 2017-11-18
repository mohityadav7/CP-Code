#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int data;
	struct node * left;
	struct node * right;
} * root = NULL;

struct node * insertNode(struct node * tNode, int value) {
	if(tNode == NULL) {
		struct node * newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	if(tNode->data > value)
		tNode->left = insertNode(tNode->left, value);
	else
		tNode->right = insertNode(tNode->right, value);
	return tNode;
}

void buildTree(int a[], int N) {
	for(int i = 0; i < N; i++) {
		if(i) {
			insertNode(root, a[i]);
		} else {
			root = insertNode(NULL, a[i]);
		}
	}
}

void inOrderTraversal(struct node * tNode) {
	if(tNode == NULL)
		return;
	inOrderTraversal(tNode->left);
	cout << tNode->data << endl;
	inOrderTraversal(tNode->right);
}

void printPath(int a[], int n){
    cout<<a[0];
    for(int i=1; i<n; i++)
        cout<<" -> "<<a[i];
    cout<<endl;
}

void rootToLeafPath(struct node *tRoot, int path[], int pathLen){
    if(tRoot == NULL)
        return;

    path[pathLen] = tRoot->data;
    ++pathLen;

    if(tRoot->left == NULL && tRoot->right == NULL){
        printPath(path, pathLen);
        return;
    }

    rootToLeafPath(tRoot->left, path, pathLen);
    rootToLeafPath(tRoot->right, path, pathLen);
}

void printRootToLeafPath(struct node * tRoot) {
    int path[100000];
    rootToLeafPath(tRoot, path, 0);
}

int main() {
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, N);
	printRootToLeafPath(root);
}
