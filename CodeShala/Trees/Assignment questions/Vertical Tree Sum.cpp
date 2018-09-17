#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
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
 
void findVerticalSum(node *root, map<long long int, long long int> &m, int x){
    if(root == NULL)
        return;
    m[x] += root->data;
    if(root->left)
        findVerticalSum(root->left, m, x-1);
    if(root->right)
        findVerticalSum(root->right, m, x+1);
}
 
vector<long long int> verticalSum(struct node * root) {
	vector<long long int> vs;
	map<long long int, long long int> m;
	findVerticalSum(root, m, 0);
	
	for(map<long long int, long long int>::iterator it = m.begin(); it != m.end(); ++it){
	    vs.push_back(it->second);
	}
	
	return vs;
}
 
int main() {
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, N);
	vector<long long int> P = verticalSum(root);
	for(int i = 0; i < P.size(); i++) {
		if(i)
			cout << " ";
		cout << P[i];
	}
	cout << endl;
}