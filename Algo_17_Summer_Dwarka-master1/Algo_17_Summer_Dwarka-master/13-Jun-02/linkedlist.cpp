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
		head=nodetoadd;

	nodetoadd->next= head;
	head= nodetoadd;
}
Node* takeinput(int n)
{
	//take n numbers and add each successive number to the front of linked list
	//take n numbers and add each successive number to the front of linked list
	/*Node* new_node = new Node(n);
	
	return new_node;*/
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
    Node* temp= head;
    while(head!=NULL)
    {
    	cout<<head->data<<" ";
    	head= head->next;
    }
}
int main() {

	int n;
	cin>>n;
	takeinput(n);
	print(head);

}