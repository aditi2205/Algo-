#include <iostream>
#include<bits/stdc++.h>
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
void addtofront(Node* &head, Node* nodetoadd)
{
	if(head==NULL)
		{head=nodetoadd;
			return;
		}
    Node* temp= head;
    while(temp->next!=NULL)
    temp= temp->next;
    temp->next= nodetoadd;
/*	nodetoadd->next= head;
	head= nodetoadd;*/
}
Node* takeinput(int n)
{
	//take n numbers and add each successive number to the front of linked list

	Node* head=NULL;
	for(int i=0; i<n; ++i)
	{
		int num;
		cin>>num;
		Node* newnode= new Node(num);
		addtofront(head, newnode);
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
void deletedup(Node* &head)
{
    Node* curr= head;
    Node* nxt;
    while(curr && curr->next)
    {
    
   /*   if(curr->next->data==curr->data)
      curr->next= curr->next->next;*/
      if(curr->next->data== curr->data)
      {
          nxt= curr->next->next;
          delete(curr->next);
          curr->next= nxt;
          
      }
      
      
      else
      curr= curr->next;
    }
}
void oddeven(Node* head)
{
	Node* odd= NULL;
	Node* even= NULL;
	Node* taile=NULL;
	Node*tailo=NULL;
	Node* curr= head;
	while(curr )
	{
		if(curr->data%2==0)
		{
			if(even==NULL)
			{
				even= curr;
				taile= even;
			}
			else
			{
				taile->next= curr;
				taile= taile->next;
			}
		}
		else
		{
			if(odd==NULL)
			{
				odd= curr;
				tailo= odd;
			}
			else
			{
				tailo->next= curr;
				tailo= tailo->next;
			}
		}
		curr= curr->next;
	}
	if(even && odd)
{
    taile->next=NULL;
    tailo->next= even;
	print(odd);
}
else if(even)
print(even);
else if(odd)
print(odd);
	cout<<"\n";
	
}
int main() {

int t;
cin>>t;
while(t--)
{
	int n;
	cin>>n;
	Node* head;
	head=takeinput(n);
	//deletedup(head);
	//print(head);
	oddeven(head);
	
}
}

