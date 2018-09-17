#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
#define ll long long int
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
 
/* Implement this method */
void zigZagTraversal(struct node * root) {
    if(root == NULL)
        return;
    stack<node *> s, t;
    
    int size;
    s.push(root);
    while(!s.empty() || !t.empty()){
        
        size = s.size();
        for(int i=0; i<size; ++i){
            node *f = s.top();
            s.pop();
            if(f->right)
                t.push(f->right);
            if(f->left)
                t.push(f->left);
            cout << f->data << " ";
        }
        
        size = t.size();
        for(int i=0; i<size; ++i){
            node *f = t.top();
            t.pop();
            if(f->left)
                s.push(f->left);
            if(f->right)
                s.push(f->right);
            cout << f->data << " ";
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
    zigZagTraversal(root);
    cout << endl;
}