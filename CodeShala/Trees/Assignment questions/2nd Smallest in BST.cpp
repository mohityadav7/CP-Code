#include <bits/stdc++.h>
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
 
void levelOrderTraversal(struct node * tnode) {
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
 
// function to return second smallest element in a BST
int secondSmallestInBST(struct node *node) {
    if(node == NULL || (node->left == NULL && node->right == NULL)){
        cout<<"Error: Number of nodes are less than 2"<<endl;
        return INT_MIN;
    }
    // if node->left is null and node->right isn't null
    if(node->left == NULL){
        // return smallest of node->right - working
        struct node *ans = NULL;
        ans = node->right;
        while(ans->left != NULL)
            ans = ans->left;
        return ans->data;
    }
    // node->left isn't null
    else{
        // finding smallest node and its parent going left from parent node - working
        struct node *s = NULL, *parent = node;
        while((parent->left)->left != NULL)
            parent = parent->left;
        s = parent->left; // now, parant = parent of s, and s = leftmost of head node
        
        // if smallest->right is null return parent of smallest - working
        if(s->right == NULL)
            return parent->data;
            
        // else if smallest->right isn't null, return smallest of right - working
        else{
            struct node *sr = s->right;
            while(sr->left != NULL)
                sr = sr->left;
            return sr->data;
        }
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
	//levelOrderTraversal(root);
	cout << secondSmallestInBST(root) << endl;
}