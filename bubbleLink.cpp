#include<iostream>
#include "mylist.h"
using namespace std;

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
void bubblesort(Node* &head)
{
	int len= length(head);
	for(int i=0; i<len; i++)
	{
		Node* prev=NULL;
		Node* curr= head;
		while(curr!=NULL && curr->next)
		{
			Node* ahead=curr->next;
			if(curr->data>ahead->data)
			{
				if(prev==NULL)
				{
					curr->next= ahead->next;
					ahead->next= curr;
					head= ahead;
					prev=ahead;
				}
				else
				{
					prev->next= ahead;
					curr->next= ahead->next;
					ahead->next= curr;
					prev=ahead;
				}
			}
			else
			{
				prev= curr;
				curr= ahead;
			}
		}
	}
}
/*void selectionsort(Node* &head)
{
   int len= length(head);
   Node* head1= head;
   Node* prev=NULL, prev2=NULL;
   Node* temp= head->next;
   for(int i=0; i<n-1; i++)
   {
   	int min= head1->data;
   	
   	  Node* curr= head1;
   	  while(temp!=NULL)
   	  {
   	  	if(temp->data<min)
   	  	{
            curr= temp;
            min= temp->data;
   	  	}
   	  	temp= temp->next;
   	  }

   	  //swap head1 and curr

   }
}*/

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
	Node* head= takeinput();
	//bubblesort(head);
	insertionsort(head);
	//print(head);
}