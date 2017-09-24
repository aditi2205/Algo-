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
Node* kreverse(Node* &head, int k1)
{
   if(head==NULL)
    return NULL;
  int k=k1;
  Node* curr= head;
  Node* prev=NULL;
  Node* ahead;
  while(curr && k>0)
  { ahead= curr->next;
    curr->next= prev;
    prev= curr;
    curr= ahead;
    k--;
  }
  //head= prev;
  if(ahead!=NULL)
  {
    head->next= kreverse(ahead,k1);
  }
  //head=curr;
  return prev;
}
int main() {
    
    Node* head;
    
    head=takeinput();
    
    print(head);
    int k;
    cin>>k;
    head=kreverse(head,k);

    print(head);
    
	return 0;
}