//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include "mytree.h"
using namespace std;

int search(int arr[], int be, int en, int x){
	while(be <= en){
		if (arr[be] == x)	return be;
		++be;
	}
}
//work out this solution
/*int find(vector<int>& a, int s, int e, int data)
 {
     for(int i=s; i<=e; i++)
     {
         if(a[i]==data)
         return i;
     }
     return -1;
 }
 TreeNode* build(vector<int>&in, vector<int>& post, int low, int high)
 {
     static int i = high;
     if(low>high)
     return NULL;
     
     
     TreeNode* root= new TreeNode(post[i--]);
     
     int index= find(in, low, high, root->val);
     root->right= build(in, post, index+1, high);
     root->left= build(in, post, low, index-1);
     return root;
 }

*/
Node * arrToTree(int in[], int pre[], int be, int en){
	/*
	arrToTree RETURNS a tree constructed from in within range [be, en] and using pre
	*/

	static int i = en;
	if (be > en){
		return NULL;
	}

	Node * root = new Node(pre[i--]);

	int idx = search(in, be, en, root->data);

	root->right = arrToTree(in, pre, idx + 1, en);
	root->left = arrToTree(in, pre, be, idx - 1);
	
	return root;

}


int main() {

	int pre[] = {4,5,2,6,7,3,1};
	int in[] = {4,2,5,1,6,3,7};

	Node * 	tree = arrToTree(in, pre, 0, 6);

	// preorder(tree);
	// cout << endl;
	// inorder(tree);

	printLevel(tree);
}