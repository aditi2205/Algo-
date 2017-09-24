#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int n)
    {
        data=n;
        left=NULL;
        right=NULL;
    }
};
Node* takeinput()
{
    
    int val;
    bool choice=0;
    string s1,s2;
    
    cin>>val;
    Node* root= new Node(val);
 
    cin>>s1;
    if(s1[0]=='t')
        choice=1;
    if(choice)
    {
        root->left= takeinput();
    }
    bool c2=0;
    cin>>s2;
    if(s2[0]=='t')
        c2=1;
    if(c2)
    {
        root->right= takeinput();
    }


   return root;
  

}
int removeleaves(Node* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        {
            return -1;
        }
    int l=removeleaves(root->left);
    int r=removeleaves(root->right);
    if(l==-1)
        root->left=NULL;
    if(r==-1)
        root->right=NULL;
    return 1;
}
int sumtreeval(Node* root)
{
    if(root==NULL)
        return 0;
    int left= sumtreeval(root->left);
    int right= sumtreeval(root->right);
    int val= left+ right+ root->data;
    return val;
}
void printnew(Node* root)
{
    if(root==NULL)
        return;
    if(root->left)
        cout<<root->left->data<<" => ";
    else
        cout<<"END => ";
    cout<<root->data;
    if(root->right)
        cout<<" <= "<<root->right->data;
    else
        cout<<" <= END";
    cout<<"\n";
    printnew(root->left);
    printnew(root->right);
}
void printtree(Node* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    printtree(root->left);
    printtree(root->right);
}
int main() {
    Node* root= takeinput();
    //cout<<"\n";
    //cout<<sumtreeval(root);
    //cout<<"\n";
    int c=removeleaves(root);
   // printtree(root);
    printnew(root);
	return 0;
}