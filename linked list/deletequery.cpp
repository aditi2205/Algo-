#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int n)
    {
        data= n;
        next=NULL;
    }
};
void addnode(Node* &head, Node* newnode)
{
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    Node* temp= head;
    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    temp->next= newnode;
}
Node* takeinput(int n)
{
    Node* head=NULL;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        Node* newnode= new Node(x);
        addnode(head, newnode);
    }
    return head;
}
void print(Node* head)
{
    Node* temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<"\n";
}
void deletenode(Node* &head, int x, int n)
{
    Node* temp= head;
    if(x==0)
    {
        head= temp->next;
        return;
    }
    /*else if(x==n-1)
    {
        while(temp->next->next!=NULL)
        temp= temp->next;
        
        temp->next=NULL;
    }*/
    else
    {
        int count= 0;
        Node* prev=head;
        temp= head->next;
        while((count!=(x-1)) && temp!=NULL)
        {
            prev= temp;
            temp= temp->next;
            count++;
        }
        if(temp!=NULL)
    {    prev->next= temp->next;
        delete(temp);
    }

    }
   // print(head);
    
}
int main() {
    int n,q;
    cin>>n>>q;
    Node* head= takeinput(n);
    //print(head);
      int a[q];
    for(int i=0; i<q; i++)
    {
      
        cin>>a[i];
    }
     for(int i=0; i<q; i++)
    {
    deletenode(head,a[i],n);
    print(head);
    n--;
}

    
	return 0;
}