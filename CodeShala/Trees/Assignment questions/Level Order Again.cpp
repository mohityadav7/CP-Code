#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define f_in(st) freopen(st,"r",stdin);
#define f_out(st) freopen(st,"w",stdout);
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

void levelOrderTraversal(struct node * tnode) {
    /*
    int local_level=0;
    int level=0;
    pair <struct node *, int> p = make_pair(local_level, 0);
    queue < pair < struct node *, int > > q;

    */
    queue <node *> q;
    if(tnode)
        q.push(tnode);

    while(!q.empty()){
        int noLevelNodes = q.size();
        while(noLevelNodes--){
            if(q.front()->left != NULL)
                q.push(q.front()->left);
            if(q.front()->right != NULL)
                q.push(q.front()->right);

            cout<<q.front()->data<<" ";
            q.pop();
        }
        cout<<endl;
    }
}

int main() {
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, N);
	levelOrderTraversal(root);
}
