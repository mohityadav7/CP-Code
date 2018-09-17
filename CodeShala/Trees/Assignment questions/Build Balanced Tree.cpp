#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node {
	int data;
	struct node * left;
	struct node * right;
	int h;
} * root = NULL;
 
struct node *newNode(int val){
    struct node *t = new node();
    t->left = NULL;
    t->right = NULL;
    t->data = val;
    t->h = 0;
    return t;
}
 
int height(node *r){
    if(r == NULL)
        return -1;
    int lh = -1, rh = -1;
    if(r->left)
        lh = r->left->h;
    if(r->right)
        rh = r->right->h;
    return max(rh, lh) + 1;
}
 
struct node *leftRotate(node *r){
    if(r == NULL)
        return NULL;
    node *right = r->right;
    node *rl = NULL;
    if(right)
        rl = right->left;
    
    r->right = rl;
    right->left = r;
    
    // update height
    r->h = height(r);
    right->h = height(right);
    
    return right;
}
 
struct node *rightRotate(node *r){
    if(r == NULL)
        return NULL;
    node *left = r->left;
    node *lr = NULL;
    if(left)
        lr = left->right;
    
    r->left = lr;
    left->right = r;
    
    // update height
    r->h = height(r);
    left->h = height(left);
    
    return left;
}
 
int bal_f(node *r){
    if(r == NULL)
        return 0;
    return height(r->left) - height(r->right);
}
 
node *insertNode(node *r, int val){
    if(r == NULL)
        return newNode(val);
    if(r->data > val)
        r->left = insertNode(r->left, val);
    else if(r->data < val)
        r->right = insertNode(r->right, val);
    
    // update height
    r->h = height(r);
    
    if(bal_f(r) > 1 && val < r->left->data){
        // left left case
        r = rightRotate(r);
    }
    else if(bal_f(r) > 1 && val > r->left->data){
        // left right case
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    if(bal_f(r) < -1 && val > r->right->data){
        // right right case
        return leftRotate(r);
    }
    else if(bal_f(r) < -1 && val < r->right->data){
        // right left case
        r->right = rightRotate(r->right);
        r = leftRotate(r);
    }
    
    return r;
}
 
void buildTree(int a[], int N) {
    // root = NULL;
    if(N > 0)
        root = newNode(a[0]);
    for(int i=1; i<N; ++i){
        root = insertNode(root, a[i]);
    }
}
 
bool isBalancedTree(struct node * root, int* height) {
  int lh = 0, rh = 0;
  int l = 0, r = 0;
     
  if(root == NULL)
  {
    *height = 0;
     return 1;
  }
 
  l = isBalancedTree(root->left, &lh);
  r = isBalancedTree(root->right,&rh);
  *height = (lh > rh? lh: rh) + 1;
  if((lh - rh >= 2) || (rh - lh >= 2))
    return 0;
     
  else return l&&r;
}
 
void levelOrder(node *r){
    if(r == NULL)
        return;
    queue<node *> q;
    q.push(r);
    
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; ++i){
            node *f = q.front();
            q.pop();
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
            cout << f->data << " ";
        }
        cout << endl;
    }
}
 
void inorder(node *r){
    if(r == NULL)
        return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}
 
int main() {
	int N, height = 0;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, N);
// 	cout << "level order: " << endl; levelOrder(root); cout << endl;
// 	cout << "inorder: " << endl; inorder(root); cout << endl;
	
	if(isBalancedTree(root, &height))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}