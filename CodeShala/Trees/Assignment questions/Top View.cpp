#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
#define ll long long int
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
void topView(struct node * root) {
    if(root == NULL)
        return;
    
    queue< pair<node *,int> > q;
    map<int, int> m;
    q.push(make_pair(root, 0));
   
    int size;
    while(!q.empty()){
        size = q.size();
        for(int i=0; i<size; ++i){
            node *f = q.front().first;
            int hd = q.front().second;
            if(m.find(hd) == m.end())
                m[hd] = f->data;
            
            if(f->left)
                q.push(make_pair(f->left, hd-1));
            if(f->right)
                q.push(make_pair(f->right, hd+1));
            q.pop();
       }
   }
    for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it){
        cout << it->second << " ";
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
    topView(root);
    cout << endl;
}