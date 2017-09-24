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

void addtofront(Node* &head, Node* nodetoadd)
{
	if(head==NULL)
		{head=nodetoadd;
			return;
		}

	nodetoadd->next= head;
	head= nodetoadd;
}
Node* takeinput()
{
	int num;
	Node* head=NULL;
	while(cin>>num && num!=-1)
	{
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