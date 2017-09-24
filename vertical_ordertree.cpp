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
ostream& operator<<(ostream &op,node* root)
{
	/*if(root==NULL)
		return;
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
*/node* delim= new node('\0');
  queue<node*> q;
  q.push(root);
   q.push(delim);
  while(!q.empty())
  {
  	

  	node* temp= q.front();
  	if(temp->data=='\0')
  			{op<<"\n";
  			
  		     q.pop();
  		     if(!q.empty())
  		     q.push(delim);
  			    
  			}
  		else{
  	
  	op<<temp->data<<" ";
  	q.pop();
  	if(temp->left)
  	q.push(temp->left);
  if(temp->right)
  	q.push(temp->right);


        }
  }
return op;
}

map<int, vector<int> > hash;
void verticalorder(node* root, int hd)
{
    if(root==NULL)
    	return;
     if(hash.find(hd)!=hash.end())
     {
     	hash[hd].push_back(root->data);
     }
     else
     {
     	vector<int> ans;
     	ans.push_back(root->data);
     	hash.insert(make_pair(hd,ans));
     }
    verticalorder(root->left, hd-1);
    verticalorder(root->right, hd+1);
}
int main()
{
	node* root= takeinput();
	cout<<root;

	verticalorder(root, 0);

	map<int, vector<int> >::iterator it;
	for(it= hash.begin(); it!=hash.end(); it++)
	{
		vector<int> res= it->second;
		for(int i=0; i<res.size(); i++)
			cout<<res[i]<<" ";
		cout<<"\n";
	}
}