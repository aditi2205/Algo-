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
Node* reverse(Node* &p)
{
  // Node* curr= head;
  // Node* prev=NULL;
  // while(curr)
  // {
  //   Node* ahead= curr->next;
  //   curr->next= prev;
  //   prev=curr;
  //   curr=ahead;
  // }
  // head= prev;
  
  if(p->next==NULL)
  {
    return p;
  }
  Node* r=reverse(p->next);
  Node* q= p->next;
  q->next=p;
  p->next=NULL;
  return r;
}
int main() {
    
    Node* head;
    
    head=takeinput();
    
    print(head);

    head=reverse(head);

    print(head);
    
	return 0;
}