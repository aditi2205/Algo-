/*#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	//insertion sort
	for(int i=1; i<n; i++)
	{
		int value= a[i];
		int hole= i;
		while(hole>0 && a[hole-1]>value)
		{
			a[hole]=a[hole-1];
			hole= hole-1;
		}
		a[hole]=value;
	}

	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
}
*/
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

void insertionsort(Node* &head)
{
	Node* sorted= NULL;
	Node*curr= head;
	Node* ahead;
	while(curr)
	{

		ahead= curr->next;
		if(sorted==NULL || sorted->data>curr->data)
		{
			curr->next= sorted;
			sorted= curr;
			curr= ahead;
		}
		// else if(sorted->next==NULL)
		// {
		// 	sorted->next= curr;
		// 	curr->next=NULL;
		// 	curr= ahead;
		// }
		else
		{
			Node* temp= sorted;
			Node* prev;
			while(temp)
			{
				prev= temp;
				temp= temp->next;
				if(prev->next==NULL||(curr->data<prev->next->data ))
				{
					prev->next= curr;
					curr->next= temp;
					break;
				}
			}
			// while(temp)
			// {
			// 	Node* s= temp;
			// 	temp= temp->next;
			// 	if(s->next==NULL|| s->next->data>curr->data)
			// 	{
			// 		s->next= curr;
			// 		curr->next= temp;
			// 		break;
			// 	}
			// }
			curr= ahead;
		}
		
		

	}
	print(sorted);
}
int main()
{
    int n;
    cin>>n;
	Node* head= takeinput(n);
	//bubblesort(head);
	insertionsort(head);
	//print(head);
}