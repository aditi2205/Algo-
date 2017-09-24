#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	//variable to hold address of the next node: (hold address): 
	//class is a blueprint: 
	Node* next;  //self referential class
	Node* random;
	Node(int num)
	{
		data=num;
		next=NULL;
		random= NULL;
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
    	cout<<head1->data<<"->";
    	head1= head1->next;
    }
}
Node* printrandom(Node* head)
{
    Node* head1= head;
    while(head1!=NULL)
    {
    	cout<<head1->data<<"->";
    	head1= head1->random;
    }
}
void setrandom(Node* head)
{
	Node* temp= head;

	while(temp!=NULL)
	{	int x;
		cout<<"enter random node";
		cin>>x;
		if(x==0)
			temp->random=NULL;
		else
		{
		Node* curr= head;
		while(curr!=NULL)
		{
			if(x!=0 && curr->data==x)
				{	cout<<"Node found\n";
				break;
			}
			curr= curr->next;
		}

		temp->random= curr;
	}

		temp = temp->next;
	}

}

void clonelist(Node* head)
{

	Node* temp= head;
	while(temp!=NULL)
	{
		Node* newnode= new Node(temp->data);
		
		Node* curr= temp->next;
		temp->next= newnode;
		newnode->next= curr;

		temp= temp->next;
		

	}
	print(head);
}
int main()
{
  	int n;
    cin>>n;

	Node* head= takeinput(n);
	print(head);

	//setrandom(head);
	//printrandom(head);
	clonelist(head);
}