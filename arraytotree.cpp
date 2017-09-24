#include <iostream>
#include<queue>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left, *right;
    Node(int n)
    {
        data=n;
        left=right= NULL;
    }
};


void printnew(Node* root)
{
    if(root->data==0)
        return;
    if(root->left )
        cout<<root->left->data<<" => ";
    else 
        cout<<"END => ";
    cout<<root->data;
    if(root->right )
        cout<<" <= "<<root->right->data;
    else 
        cout<<" <= END";
    cout<<"\n";
    printnew(root->left);
    printnew(root->right);
}
int find(std::vector<int> v, int val, int start, int end)
{
    for(int i=start; i<end; i++)
    {
        if(v[i]==val)
            return i;
    }
    return -1;
}
Node* createtree(std::vector<int> pre, std::vector<int> in, int pres, int pree, int ins, int ine)
{
   /* cout<<"\n"<<pres<<" "<<pree<<"\n";
    cout<<"\n"<<ins<<" "<<ine<<"\n";
   */ if(pres>pree)
        return NULL;
    if(ins>ine)
        return NULL;
    Node* root;
    int val= pre[pres];
    root= new Node(val);

    int index= find(in, val, ins, ine);
   // cout<<"\nindex of "<<val<<" in inorder array is"<<index<<"\n";
    int lsize= index-ins;
    if(index!=-1)
    {
        root->left= createtree(pre, in, pres+1, pres+lsize+1, ins, index);
        root->right= createtree(pre, in, pres+1+lsize, pree, index+1, ine);
    }
    return root;
}
void print(Node* root){
    //preorder Traversal --> root left right
    if (root == NULL) return;

    cout << root->data << " ";
    print(root->left);
    print(root->right);
}
int main() {
    
    int n,m;
    cin>>n;
    vector<int>pre, in;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        pre.push_back(x);
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int x;
        cin>>x;
        in.push_back(x);
    }
    
    Node* root;
    root= createtree(pre, in, 0,n,0, m);
   printnew(root);
    
   


    
}
