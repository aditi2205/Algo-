#include<iostream>
#include<math.h>
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
int getlen(Node* head)
{
  Node* temp= head;
  int count=0;
  while(temp!=NULL)
  {
    temp= temp->next;
    count++;
  }
  return count;
}
int intersection(Node* head1,Node* head2, int d)
{
  Node* temp= head1;
  while(d--)
  {
    if(temp)
      temp= temp->next;
  }
  while(temp && head2)
  {
    if(temp==head2)
      return temp->data;
    temp= temp->next;
    head2= head2->next;
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
     head->next->next->next->next->next = new Node(18);
      head->next->next->next->next->next->next = new Node(31);
      head->next->next->next->next->next->next->next = new Node(32);
      head->next->next->next->next->next->next->next->next = new Node(33);

      Node* head1= new Node(2);
      
    head1->next = new Node(12);
    head1->next->next = new Node(14);
    //head1->next->next->next->next = new Node(16);
    head1->next->next->next= head->next->next->next->next;
    
    print(head);
    //detect(head);
    cout<<"\n";
    print(head1);
    //print(head);
    int l1= getlen(head);
    cout<<l1<<"\n";
    int l2= getlen(head1);
    cout<<l2<<"\n";
    int d;
    if(l1>l2)
    {
      d=l1-l2;
      cout<<intersection(head, head1,d);
    }
    else
    {
      d= l2-l1;
       cout<<intersection(head1, head, d); 
    }
    
	return 0;
}