// #include<iostream>
// #include "mylist.h"
// using namespace std;

// Node* mergeit(Node* &head1, Node* &head2){

// 	Node* a= head1;
// 	Node* b= head2;
// 	Node* res=NULL;

// 	if(a==NULL)
// 		return b;
// 	if(b==NULL)
// 		return a;
// 	if(a==NULL && b==NULL)
// 		return res;
// 	if(a->data<b->data)
// 	{
// 		res=a;
// 		res->next=mergeit(a->next,b);
// 	}
// 	else if(a->data>b->data)
// 	{
// 		res=b;
// 		res->next=mergeit(a,b->next);
// 	}


// }
// void mergesort(Node* &head)
// {
// 	if(head==NULL || head->next==NULL)
// 		return;
	
// 	Node* slow= head;
// 	Node* fast= head;
	

// 	while(slow&&fast&&fast->next&& fast->next->next)
// 	{
// 		slow= slow->next;
// 		fast= fast->next->next;
// 	}
//    Node* second= slow->next;
//    slow->next=NULL;
//     Node* first= head;
//    mergesort(first);
//    mergesort(second);

//    Node* sortedlist=mergeit(first, second);

//   head=sortedlist;

// }
// int main()
// {

// 	Node* head= takeinput();
// 	cout<<"\n";
// 	print(head);
// 	cout<<"mergesort\n";
// 	mergesort(head);
// 	print(head);
// }
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
Node* mergeit(Node* &head1, Node* &head2){

	Node* a= head1;
	Node* b= head2;
	Node* res=NULL;

	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	if(a==NULL && b==NULL)
		return res;
	if(a->data<b->data)
	{
		res=a;
		res->next=mergeit(a->next,b);
	}
	else if(a->data>b->data)
	{
		res=b;
		res->next=mergeit(a,b->next);
	}


}
void mergesort(Node* &head)
{
	if(head==NULL || head->next==NULL)
		return;
	
	Node* slow= head;
	Node* fast= head;
	

	while(slow&&fast&&fast->next&& fast->next->next)
	{
		slow= slow->next;
		fast= fast->next->next;
	}
   Node* second= slow->next;
   slow->next=NULL;
    Node* first= head;
   mergesort(first);
   mergesort(second);

   Node* sortedlist=mergeit(first, second);

  head=sortedlist;

}
int main()
{
    int n;
    cin>>n;

	Node* head= takeinput(n);
	
	mergesort(head);
	print(head);
}