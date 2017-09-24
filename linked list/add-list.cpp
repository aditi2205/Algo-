#include<iostream>
#include"mylist.h"
using namespace std;

Node* reverse(Node *head)
{
	if(head==NULL || head->next==NULL)
		return head;
	Node* newhead=reverse(head->next);

	head->next->next= head;
	head->next=NULL;
	return newhead;
}
int length(const Node* head)
{
	int count=0;
	const Node* temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}
Node* simpleadd(const Node* head1, const Node* head2, int *carry)
{
	if(head1==NULL )
	{
		return NULL;
	}
	Node* res= new Node(0);
	res->next= simpleadd(head1->next, head2->next, carry);
	int a=0,b=0,sum=0;
	if(head1) a= head1->data;
	if(head2) b= head2->data;
	sum= a+b+(*carry);
	(*carry)= sum/10;
	sum= sum%10;
	res->data= sum;
	return res;


}
void addtorem(const Node* n1, const Node* curr, Node *ans, int *carry)
{
   if(n1==NULL)
   	return;
   if(n1!=curr)
   addtorem(n1->next, curr, ans, carry);
   
   int sum= n1->data+ (*carry);
   *carry= sum/10;
   sum= sum%10;
   Node* newnode= new Node(sum);
   addtofront(ans,newnode);
}
void addnumber(const Node* n1, const Node* n2)
{	int a= length(n1);
	int b= length(n2);
     int carry=0;
     Node* ans;
	if(a==b)
		{ans= simpleadd(n1, n2, &carry);}
	else
		{int d;
	if(a<b)
	{
		const Node* temp = n1;
		n1=n2;
		n2=temp;
		d=b-a;
	}
	else  d=a-b;
	int d1=d;
	const Node* curr= n1;
	while(d1--)
		curr= curr->next;

      ans= simpleadd(curr,n2, &carry);

      addtorem(n1, curr, ans, &carry);

     


}
 if(carry)
      {
      	Node* newnode= new Node(carry);
      	addtofront(ans, newnode);

      }	
    cout<<"\n";
      print(ans);




	/*n1= reverse(n1);
	n2= reverse(n2);

	Node* ans=NULL;
	Node* tail=NULL;
    int carry=0;
	while(n1 || n2)
	{
		int sum=0;
		if(n1){
			sum+=n1->data;
		    n1= n1->next;
		}
		if(n2)
			{sum+=n2->data;
				n2= n2->next;
			}
		sum+=carry;
		carry= sum/10;
		sum= sum%10;

		if(ans==NULL)
		{
			ans= new Node(sum);
			tail= ans;
			//tail= tail->next;
		}
		else
		{
			tail->next= new Node(sum);
			tail= tail->next;
		}

		

	}
	if(carry!=0)
	{
		tail->next= new Node( carry);
		tail= tail->next;
	}
	ans=reverse(ans);
	return ans;*/


}
int main()
{
	Node* head= takeinput();
	print(head);
	Node* head2= takeinput();
	print(head2);
    //int carry=0;
	//Node* ans= simpleadd(head,head2,&carry);
	addnumber(head, head2);
	


}