#include<iostream>
#include "mylist.h"
using namespace std;

void pairwise(Node* &head)
{
	Node *prev, *curr, *runner, *ahead;
	prev=NULL;
	curr=head;
	runner= head->next;
	while(curr && curr->next)
	{
		ahead= runner->next;
		runner->next= curr;
		curr->next= ahead;
		if(prev==NULL)
		{
			head= runner;
			prev= head->next;
		}
		else
		{
			prev->next= runner;
			prev= prev->next->next;
		}
		if(curr->next)
		 curr= curr->next;
		if(runner->next->next)
		 runner= runner->next->next->next;
	}
}

Node* mergeit(Node* head1, Node* head2){

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
main()
{

	Node* head= takeinput();
	/*cout<<"\n";
	print(head);
	cout<<"\n";
	Node* head2= takeinput();
	cout<<"\n";
	print(head2);
	head=mergeit(head,head2);
	cout<<"\n  merged list \n";*/
	print(head);

	pairwise(head);
	cout<<"new";
	print(head);

}