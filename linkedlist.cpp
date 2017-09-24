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

	/*nodetoadd->next= head;
	head= nodetoadd;*/
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
int main() {

	int n;
	cin>>n;
	Node* head;
	head=takeinput(n);
	print(head);

}

