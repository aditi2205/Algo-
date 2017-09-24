#include<iostream>
using namespace std;
class Node{
public:
	int data;
	//variable to hold address of the next node: (hold address): 
	//class is a blueprint: 
	Node* next;  //self referential class
	Node(int num)
	{
		data=num;
		next=NULL;
	}
};
int length(Node* head)
{
	Node* temp= head;
	int c=0;
	while(temp)
	{
		temp= temp->next;
		c++;
	}
	return c;
}
void addnode(Node* &head, Node* newnode)
{
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    Node* temp= head;
    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    temp->next= newnode;
}
Node* takeinput(int n)
{
    Node* head=NULL;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        Node* newnode= new Node(x);
        addnode(head, newnode);
    }
    return head;
}
Node* print(Node* head)
{
    Node* head1= head;
    while(head1!=NULL)
    {
    	cout<<head1->data<<" ";
    	head1= head1->next;
    }
}

void bubblesort(Node* &head)
{
   int len= length(head);
   for(int i=0; i<len; i++)
   {
       Node* curr= head;
       Node* prev=NULL;
       Node* ahead;
       while(curr && curr->next)
       {
           ahead= curr->next;
           if(curr->data>ahead->data)
           {
               if(prev==NULL)
               {
                   curr->next= ahead->next;
                   ahead->next= curr;
                   head=ahead;
                   prev= ahead;
                   
               }
               else
               {
                   prev->next= ahead;
                   curr->next= ahead->next;
                   ahead->next= curr;
                   prev= ahead;
               }
           }
           else
           {
               prev= curr;
               curr= curr->next;
           }
           
       }
   }
   print(head);
}
int main()
{
    int n;
    cin>>n;
	Node* head= takeinput(n);
	//bubblesort(head);
	bubblesort(head);
	//print(head);
}