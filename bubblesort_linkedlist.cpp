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

int midele(Node* head)
{
	Node* slow= head;
	Node* fast= head;
	while(slow&&fast&&fast->next&&fast->next->next)
	{
		slow= slow->next;
		fast= fast->next->next;
	}
	return slow->data;
}

Node* bubblesort(Node* head)
{
	Node* temp;
	Node* end= NULL;
	Node* prev=NULL;
	int swapped=0;

	do
	{
		temp=head;
		prev=NULL;
		while(temp->next!=end)
		{
			if(temp->data>temp->next->data)
			{
				//swap
				Node* nxt= temp->next;
				temp->next= nxt->next;
				nxt->next=temp;

				if(prev==NULL)
					{
						prev=nxt;
						head= prev;
					}
				else
				prev->next=nxt;


				swapped=1;
				
			}
			//prev= temp;
			temp= temp->next;
		}
		end= temp;
	}
	while(swapped);

	return head;

}
int main() {

	int n;
	cin>>n;
	Node* head;
	head=takeinput(n);
	print(head);
	//cout<<"after bubble sort\n";
	//head= bubblesort(head);
	int data= midele(head);
	cout<<data;

}

