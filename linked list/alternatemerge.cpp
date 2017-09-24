#include<iostream>
#include "mylist.h"
using namespace std;

Node* mergeit(Node* head1, Node* head2, int flag){

	Node* a= head1;
	Node* b= head2;
	Node* res=NULL;

	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	if(a==NULL && b==NULL)
		return res;
	if(flag==true)
	{
		res=a;
		res->next=mergeit(a->next,b, !flag);
	}
	else 
	{
		res=b;
		res->next=mergeit(a,b->next, !flag);
	}


}
int main()
{

	Node* head= takeinput();
	cout<<"\n";
	print(head);
	cout<<"\n";
	Node* head2= takeinput();
	cout<<"\n";
	print(head2);
	head=mergeit(head,head2,true);
	cout<<"\n  merged list \n";
	print(head);
}