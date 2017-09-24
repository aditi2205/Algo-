#include<iostream>
#include "mylist.h"
using namespace std;

int nthfromend(Node* head, int i){
	Node* ptr1= head;
	Node* ptr2= head;

	int count=1;
	while(count<=i)
	{
		ptr1= ptr1->next;
		count++;
	}
	while(ptr1)
	{
		ptr1= ptr1->next;
		ptr2= ptr2->next;

	}
	return ptr2->data;

}
int main()
{

	Node* head= takeinput();
	print(head);
	int n;
	cout<<"enter element to find from end";
	cin>>n;
	cout<<nthfromend(head,n);
	//print(head);
}