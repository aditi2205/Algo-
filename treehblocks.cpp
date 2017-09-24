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
vector<int> ans;
vector<vector<int> >res;
Node* takeinput1()
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
        root->left= takeinput1();
    }
    bool c2=0;
    cin>>s2;
    if(s2[0]=='t')
        c2=1;
    if(c2)
    {
        root->right= takeinput1();
    }


   return root;
  

}
Node* takeinput()
{
    Node* root;
    int n;
    //cout<<"\nenter data\t";
    cin>>n;
    root= new Node(n);
    int val;
    //cout<<"\nenter number of child\t";
    cin>>val;
    if(val!=0)
    {
        if(val==2)
        {
          root->left=takeinput();
          root->right= takeinput();
        }
      
    }
    return root;
}
void findsum(Node* root)
{
    queue<Node*> q;
    q.push(root);
    //ans.push_back(root->data);
    q.push(NULL);
    int count=0, sum=0;
    while(!q.empty())
    {
       // cout<<"\ncount is"<<count<<"\tsum is "<<sum<<"\n";
        
        Node* temp= q.front();
        if(temp==NULL)
        { 
            cout<<"\n";
            res.push_back(ans);
            //ans.clear();
            q.pop();
            if(!q.empty())
             q.push(NULL);
              
            
        }
        else
        {
           
            ans.push_back(temp->data);
           // cout<<"sum="<<sum<<"\n";
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left)
             q.push(temp->left);
            if(temp->right)
             q.push(temp->right);
        
        }
        
    }
    
}
void print3(Node* root)
{
    Node* delim= new Node('\0');
  queue<Node*> q;
  q.push(root);
   q.push(delim);
  while(!q.empty())
  {
    

    Node* temp= q.front();
    if(temp->data=='\0')
            {//cout<<"\n";
              res.push_back(ans);
              ans.clear();
             q.pop();
             if(!q.empty())
             q.push(delim);
                
            }
        else{
    
    //cout<<temp->data<<" ";
    ans.push_back(temp->data);
    q.pop();
    if(temp->left)
    q.push(temp->left);
  if(temp->right)
    q.push(temp->right);


        }
  }
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
    
    Node* root= takeinput1();
    
   print3(root);
     //findsum( root);
    cout<<"\n vector\n";
   cout<<"[";
    for(int i=0; i<res.size(); i++)
    {
        cout<<"[";
        for(int j=0; j<res[i].size(); ++j)
        {
            if(j<res[i].size()-1)
            cout<<res[i][j]<<",";
        else
            cout<<res[i][j];
        }
        if(i<res.size()-1)
        cout<<"],";
    else
        cout<<"]";
    }
cout<<"]";

    
}
