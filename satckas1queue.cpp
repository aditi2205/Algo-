#include<iostream>
#include<bits/stdc++.h>
using namespace std;
queue<int>q1;


void pushit(int x)
{
	int size= q1.size();
	if(q1.empty())
		q1.push(x);
	else
	{
		q1.push(x);
		while(size--)
		{
			int x=q1.front();
			q1.pop();
			q1.push(x);
		}
	}


}

int popit()
{
	if(!q1.empty())
	{
		int ele= q1.front();
		q1.pop();
		return ele;
			}
			else
				return -1;
}
int main()
{
	while(1)
	{
	cout<<"\nenter operation\t";
	int op;
	cin>>op;
	if(op==3)
		return 0;
	if(op==1)
	{
		cout<<"\nenter element to push\t";
		int x;
		cin>>x;
		pushit(x);
	}
	else
	{
		cout<<popit()<<"\n";
		cout<<"queue front\t"<<q1.front()<<"\n";

	}
}
	
}