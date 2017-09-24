#include <iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int a){
        data=a;
        left=NULL;
        right=NULL;
    }
};

Node* takeInput(){
    int data;
    cin>>data;
    
    if(data==-1)
        return NULL;
    
    Node*temp=new Node(data);
    temp->left=takeInput();
    temp->right=takeInput();
    
    
    
}
void postOrder(Node* root){
    //postorder --> left right root
    if (root == 0)  return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void printTree1(Node*root){
    
    if(root==NULL)
        return;
    
       
        cout<<root->data<<" ";
         printTree(root->left);
        printTree(root->right);
      
        
    
}
void printTree(Node*root){
    
    if(root==NULL)
        return;
    
        printTree(root->left);
        cout<<root->data<<" ";
        printTree(root->right);
      
        
    
}
Node* takeInput1(){
    //take input to construct a Binary Tree --depth wise
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    Node * root = new Node(data);
    root->left = takeInput1();   //take input for left SUBTREE 
    root->right = takeInput1();
}

Node* takeInputLevel(){
    
    int data;
    cin>>data;
    
    if(data==-1)
        return NULL;
    
    Node* root=new Node(data);
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        
        Node*par=q.front();
        q.pop();
        
        int ldata;
        cin>>ldata;
        
        if(ldata!=-1){
            Node*temp=new Node(ldata);
            par->left=temp;
            q.push(temp);        
        }
        
        int rdata;
        cin>>rdata;
        
        if(rdata!=-1){
            Node*temp=new Node(rdata);
            par->right=temp;
            q.push(temp);
        }
        
        
    }
    return root;
    
}

int main() {
	//code
	
	Node* root;
	root=takeInput1();
	printTree(root);
    cout<<"\n";
    postOrder(root);
	
	return 0;
}