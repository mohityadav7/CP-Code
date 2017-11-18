#include <iostream>
using namespace std;

//node structure
struct node{
    int data;
    node *left;
    node *right;
} *root;

//function to create a new node with data x
node *newNode(int x){
    node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->left = temp->right = NULL;
    return temp;
}

//utility function for makeTree function
node *insertNode(int x, node *head){
    if(head==NULL){
        head=newNode(x);
        return head;
    }
    if(x >= head->data)
        head->right = insetNode(x, head->right);
    else
        head->left = insertNode(x, head->left);

    return head;
}

//function to build a tree
node *makeTree(int a[], int n){
    if(n>0)
        root=newNode(a[0]);
    for(int i=0; i<n; i++){
        root = insertNode(a[i], root);
    }
    return root;
}

//Pre Order Traversal
void preOrderTraversal(node *head){
    if(head == NULL)
        return;
    preOrderTraversal(head->left);
    cout<<head->data<<" ";
    preOrderTraversal(head-right);
}

//driver function
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    makeTree(a, n);
    preOrderTraversal(root);

    return 0;
}
