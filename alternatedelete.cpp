#include<iostream>
#include"mylist.h"
using namespace std;

void altdel(Node* &head)
{
  Node* curr=head;
  while(curr)
  {
    if(curr->next)
    {
      Node* dup= curr->next;
      curr->next= curr->next->next;
      delete(dup);
    }
    curr= curr->next;
  }
}
int main() {
    
    Node* head;
    
    head=takeinput();
    
    print(head);
     cout<<"\n";
    altdel(head);

    print(head);
    
	return 0;
}