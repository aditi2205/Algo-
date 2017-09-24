#include<iostream>
#include "mylist.h"
using namespace std;

Node* reverse(Node* &head)
{
	if(head->next==NULL)
		return head;
	Node* newhead= reverse(head->next);
	head->next->next= head;
	head->next=NULL;
	return newhead;
}

Node* add(Node* head1, Node* head2, int *carry){

 Node* res= new Node(0);
 if(head1==NULL && head2==NULL)
 	return NULL;
 int a,b;

Node* temp1= head1;
Node* temp2= head2;

while(temp1 && temp2)
{
	a= temp1->data;
b= temp2->data;
	int sum= a+b+(*carry);
*carry= sum/10;
int val= sum%10;
 Node* ans= new Node(val);
 res->next= ans;

 temp1= temp1->next;

temp2= temp2->next;
}
return res;
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

	Node* res=NULL;
	res=add(head,head2,0);
	cout<<"\n  added list \n";
	print(res);

}