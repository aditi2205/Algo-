#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
class Tree{
	 public:
	int data;
	Tree* left;
	Tree* right;


 	Tree(int n)
 	{
 		data= n;
 		left= right= NULL;
 	}
};

Tree* takeinput_levelwise()
{
	Tree* root;
	int data;
	queue<Tree*> q;
	cin>>data;
	if(data!=-1)
	{root= new Tree(data);
		q.push(root);
	}
	
	while(!q.empty())

		{//fill left
		Tree* temp= q.front();
		q.pop();

		
			int x;
			cin>>x;
			if(x!=-1)
			{
				Tree* temp1= new Tree(x);
				temp->left= temp1;
				q.push(temp1);
			}

			int y;
			cin>>y;
			if(y!=-1)
			{
				Tree* temp2= new Tree(y);
				temp->right= temp2;
				q.push(temp2);
			}

		
	}
	return root;
}

void printtree(Tree* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	printtree(root->left);
	printtree(root->right);
}
pair<int, int> find_diameter(Tree* node, pair<int, int> &p)
{
    //find the diameter of left side
    //find the diameter of right side
    //calculate height of left and right sides and calculate maximum diameter
    //return p;
    if(node==NULL)
    return make_pair(0,0);
    
    pair<int, int>p1= find_diameter(node->left, p);
    pair<int, int>p2= find_diameter(node->right, p);
    
    p.first= max(p1.first, p2.first)+1;
    //height of tree
    
    p.second= max(max(p1.second, p2.second), p1.first+p2.first+1);
    
    return p;
    
}
 
 void printvector()
 {
     for(int i=0; i<v.size(); i++)
     cout<<v[i]<<" ";
     cout<<"#";
 }
void printPaths(Tree* root)
{
    // Code here
    //print path from root to leaf
    //go to left child and go to right child
    //push every node in to a vector
    //if leads to a solution then print the solution and pop the last node and then again go to left and right child
    //if does not give a solution then pop back from the vector
    
    if(root==NULL) return;
    //cout<<"pushing:"<<root->data<<"\n";
    v.push_back(root->data);
    if(root->left==NULL && root->right==NULL)
    {
        printvector();
        v.pop_back();
        return;
    }
    
   if(root->left)
    printPaths(root->left);
	if(root->right)
    printPaths(root->right);
	
	v.pop_back();
    
    
}
void diameter(Tree* node)
{
   // Your code here
   pair<int, int> p,s;
   //first= height
   //second= diameter
   p.first=0;
   p.second=0;
   p= find_diameter(node,s );
   cout<<p.first<<" "<<p.second;
}
int main()
{
	Tree *root;
	root= takeinput_levelwise();
	printtree(root);
	cout<<endl;
	//diameter(root);
	cout<<"function\n";
	printPaths(root);

}