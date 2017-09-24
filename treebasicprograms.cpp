#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
vector<int> res;
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

int sumtree(node* root)
{
	if(root==NULL)
		return 0;
	int left= sumtree(root->left);
	int right= sumtree(root->right);
	int val=left+right;
	root->data= val;
	return val;
	
}

int height(node* root)
{
	if(root==NULL)
		return 0;
	int l=0,r=0;
	l= height(root->left);
	r=height(root->right);
	return (l>r)?l+1:r+1;
}

int diameter(node* root)
{
	//mycode
	if(root==NULL)
		return 0;
	int l= height(root->left);
	int r= height(root->right);
	int max1= max(l,r)+1;
	int max2= max(max1,l+r+1);
	return max2;
	//sir code
	/*if(root==NULL)
		return 0;
	int l= diameter(root->left);
	int r= diameter(root->right);
	int max1= height(root->left)+ height(root->right)+1;
	int max2= max(max1,max(l,r));
	return max2;*/
}
int isbalanced(node* root)
{
	if(root==NULL)
		return 1;
	int left= height(root->left);
	int right= height(root->right);
	if(left-right>1 || right-left>1)
		return 0;
	return isbalanced(root->left);
	return isbalanced(root->right);

}
pair<int,int> isbalancedopt(node* root)
{

	if(root==NULL)
	{
		pair<int,int> p;
		p= make_pair(0,1);
		return p;
	}
	pair<int,int> left, right, res;
	int curheight, val=1;

	left= isbalancedopt(root->left);
	right= isbalancedopt(root->right);

	curheight= max(left.first, right.first)+1;

	if(left.first-right.first>1 || right.first-left.first>1)
		val=0;

	res= make_pair(curheight, val);

	return res;


    
}
//put all the paths from root to leaf node into the vector 
void printtoleaf(node* root, vector<int>&res1)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		res1.push_back(root->data);
		for(int i=0; i<res1.size(); i++)
			cout<<res1[i]<<" ";
		res1.pop_back();
		cout<<"\n";
	}
	res1.push_back(root->data);
	printtoleaf(root->left, res1);
	printtoleaf(root->right, res1);
	res1.pop_back();
}
void findmaxsum(node* root)
{
  
 /* queue<node*> q;
  node* delim= new node('\0');
  q.push(root);
  q.push(delim);
  int sum= 0;
  vector<int> s;
  while(!q.empty())
  {
      node* temp= q.front();
      
      if(temp->data=='\0')
      {
      	s.push_back(sum);
      	sum=0;
      	q.pop();
      }
     else
     {sum+= temp->data;
      q.pop();
      if(temp->left)
      	q.push(temp->left);
      if(temp->right)
      	q.push(temp->right);
  }
  }*/
	node* delim= new node('\0');
  queue<node*> q;
  int sum= 0;
  vector<int> s;
  q.push(root);
   q.push(delim);
  while(!q.empty())
  {
  	

  	node* temp= q.front();
  	if(temp->data=='\0')
  			{s.push_back(sum);
  				sum=0;
  			
  		     q.pop();
  		     if(!q.empty())
  		     q.push(delim);
  			    
  			}
  		else{
  	if(temp->data>=0)
  	sum+=temp->data;
  	q.pop();
  	if(temp->left)
  	q.push(temp->left);
  if(temp->right)
  	q.push(temp->right);


        }
  }
  for(int i=0; i<s.size(); i++)
  	cout<<s[i]<<" ";
  int sum1=0, sum2=0;
  for(int i=0; i<s.size(); i=i+2)
  {
      sum1+=s[i];
  }
  for(int i=1; i<s.size(); i=i+2)
  {
      sum2+=s[i];
  }
  int finalsum= max(sum1, sum2);
  cout<<"\n"<<finalsum<<"\n";
}

void mirror(node* &root)
{
	if(root==NULL)
		return ;
    node* temp= root->left;
    root->left= root->right;
    root->right= temp;
    mirror(root->left);
    mirror(root->right);
}
int main()
{
	node* root= takeinput();
	//cout<<root;
	//int c= sumtree(root);
	/*int h= height(root);
	cout<<"\n"<<h<<"\n";
	int d= diameter(root);
	cout<<"\n"<<d<<"\n";
	int b= isbalanced(root);
	cout<<"\n"<<b<<"\n";
	findmaxsum(root);
	cout<<"\n";
	mirror(root);
	cout<<root;

	pair<int,int> ans= isbalancedopt(root);
	cout<<ans.first<<" "<<ans.second;*/
	vector<int> res1;
	printtoleaf(root,res1);
	/*for(int i=0; i<ans.size(); i++)
	{
		for(int j=0; j<ans[i].size(); j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	
}
