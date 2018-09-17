#include <iostream>
#include <algorithm>
#include <queue>
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
 
int height(node *root){
    if(root == NULL)
        return -1;
    int lh=-1, rh=-1;
    if(root->left)
        lh = height(root->left);
    if(root->right)
        rh = height(root->right);
    return ((lh>rh)?lh:rh) + 1;
}
 
// bool isBalancedTree(struct node * root) {
//     if(root == NULL)
//         return true;
//     if(abs(height(root->left) - height(root->right)) > 1)
//         return false;
//     return isBalancedTree(root->left) && isBalancedTree(root->right);
// }
 
bool isBalancedTree(struct node * root, int &height) {
    if(root == NULL){
        height = -1;
        return true;
    }
    
    int lHeight, rHeight;
    bool isLeftBalanced, isRightBalanced;
    
    isLeftBalanced = isBalancedTree(root->left, lHeight);
    isRightBalanced = isBalancedTree(root->right, rHeight);
    
    height = ((lHeight > rHeight) ? lHeight : rHeight) + 1;
    
    if(abs(lHeight - rHeight) > 1)
        return false;
    else return isLeftBalanced && isRightBalanced;
}
 
int main() {
	int N, height = 0;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, N);
	if(isBalancedTree(root, height))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}