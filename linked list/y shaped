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
    Node* curr=head;
    Node* exist=NULL;
    while(curr!=NULL)
    {
      if(curr->data==newnode->data)
        exist= curr;
      curr= curr->next;
    }
    while(temp->next!=NULL)
    {
        temp= temp->next;  
    }
    if(exist)
      temp->next= exist;
    else
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
    int count= 10;
    while(temp!=NULL && count--)
   { 
    cout<<temp->data<<" ";
      temp=temp->next;
}
cout<<"\n";
}

void detect(Node* head)
{
  Node* slow= head;
  Node* fast= head;
  bool cycle=false;
  while(slow&&fast&&fast->next)
  {
    slow= slow->next;
    fast= fast->next->next;
    if(slow==fast)
      {cycle=true;
        break;
      }
  }
  // cout<<"\n"<<cycle;
  if(cycle)
    {
      fast= head;
      while(slow->next!=fast->next)
      {
        slow= slow->next;
        fast= fast->next;
      }
      slow->next= NULL;
      cout<<"\n"<<slow->data;
    }
}

int main() {
    
    // Node* head;
    
    // head=takeinput();
    Node *head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next= head->next;
    print(head);
    detect(head);
    cout<<"\n";
    print(head);
    //print(head);
    
	return 0;
}