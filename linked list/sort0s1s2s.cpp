#include<iostream>
#include"mylist.h"
using namespace std;


void sortlist(Node* &head)
{
	Node *zero, *ztail, *one, *otail, *two, *ttail;
	zero=NULL;
	one= NULL;
	two=NULL;
	Node* curr= head;
	ztail= NULL;
	otail=NULL;
	ttail=NULL;
	while(curr)
	{
		if(curr->data==0)
		{
			if(zero==NULL)
			{
				zero= curr;
				ztail= zero;
			}
			else
			{
				ztail->next= curr;
				ztail= ztail->next;
			}
		}
		else if(curr->data==1)
		{
			if(one==NULL)
			{
				one= curr;
				otail= one;
			}
			else
			{
				otail->next= curr;
				otail= otail->next;
			}
		}
		else if(curr->data==2)
		{
			if(two==NULL)
			{
				two= curr;
				ttail= two;
			}
			else
			{
				ttail->next= curr;
				ttail= ttail->next;
			}
		}
		curr= curr->next;
	}
	// print(zero);
	// cout<<"\n";
	// print(one);
	// cout<<"\n";
	// print(two);
	// cout<<"\n";
	ztail->next= one;
	otail->next=two;
	ttail->next=NULL;
	print(head);
}
int main()
{
	Node* head= takeinput();
	print(head);
	cout<<"\n";
	sortlist(head);
	//print(head);
}