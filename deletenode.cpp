#include<iostream>
using namespace std;
class Node
{
  public:
  int data;
  Node* next;
  Node(int num)
  {
      data= num;
      next= NULL;
  }
};
void addata(Node* &head, Node* newnode)
{
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    Node* temp =head;
    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    temp->next= newnode;
}
Node* takeinput(){
   int n,num;
   cin>>n;
   Node* head= NULL;
   for(int i=0; i<n; i++)
   {
      cin>>num;
      Node* newnode= new Node(num);
      addata(head,newnode);
   }
   return head;
   
}
void print(Node* head)
{
    Node* temp= head;
    while(temp!=NULL)
   { cout<<temp->data<<" ";
 temp=temp->next;
}
cout<<"\n";
}
Node* findnode(Node* head, int val)
{
  Node* temp = head;
  while(temp!=NULL)
  {
    if(temp->data==val)
      return temp;
  }
  return NULL;
}
void deletenode(Node* &node)
{
 
    node->data= node->next->data;
    node->next= node->next->next;
  
  delete(node->next);
  return;
}
int main() {
    
    Node* head;
    
    head=takeinput();
    
    print(head);

    cout<<"enter data of node to be deleted";
    int num;
    cin>>num;
    Node* node= findnode(head,num);
    cout<<node->data;
   if(node==NULL)
    {cout<<"no such node exists";
  return 0;
    }
deletenode( node);
    print(head);
    
	return 0;
}