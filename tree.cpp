#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
	node(int n)
	{
		data=n;
		left=NULL;
		right=NULL;
	}
};
node* takeinput()
{
	//depth wise input
	/*int n;
	cin>>n;
	if(n==-1)
		return NULL;
	node* root= new node(n);
	root->left= takeinput();
	root->right=takeinput();*/

	//level wise input
	int n;
	cin>>n;
	if(n==-1) return NULL;
	node* root1= new node(n);
	queue<node*> q;
	q.push(root1);
	while(!q.empty())
	{
		node* root=q.front();
		q.pop();
		int ldata; cin>>ldata;
		if(ldata!=-1)
		{
			node* temp= new node(ldata);
			root->left= temp;
			q.push(temp);
		}
		int rdata; cin>>rdata;
		if(rdata!=-1)
		{
			node* temp= new node(rdata);
			root->right= temp;
			q.push(temp);
		}
		
	}
	return root1;

}
istream& operator>>(istream& op, node* &root)
{
	//depth wise input
	root= takeinput();
	return op;

	//level wise input
	
}
void print(node* root)
{
	node* delim= new node('\0');
  queue<node*> q;
  q.push(root);
   q.push(delim);
  while(!q.empty())
  {
  	

  	node* temp= q.front();
  	if(temp->data==delim->data)
  			{cout<<"\n";
  		     q.pop();
  		     if(!q.empty())
  		     {
  		     	q.push(delim);
  		     	
  		     }
  		 }
  	else{
  	
  	cout<<temp->data<<" ";
  	q.pop();
  	if(temp->left)
  	q.push(temp->left);
  if(temp->right)
  	q.push(temp->right);
 

}
  }
}
ostream& operator<<(ostream& op, node* root)
{
	/*if(root==NULL)
		return;
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
*/
	print(root);
return op;
}
void inorder(node* root)
{
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main()
{
	//node* root= takeinput();
	//node* root=takeinput();
	node* root= NULL;
	cin>>root;
	cout<<root;
	//print(root);
	inorder(root);
}