#include<iostream>
#include<bits/stdc++.h>
using namespace std;
queue<int>q1;
queue<int>q2;
stack<int> s;
void pushit(int x)
{
	if(s.empty())
	{
		s.push(x);
	}
	else if(s.top()>x)
		s.push(x);
	else if(s.top()<=x)
	{
		int ele= s.top();
		s.push(ele);
	}
}

int popit()
{
	if(!s.empty())
	{
		s.pop();
		return s.top();
		
	}
	else
		return -1;
}
int minele()
{
	if(!s.empty())
	return s.top();
else
	return -1;
}
void printtop()
{
     cout<<"top of the stack"<<s.top()<<"\n";
}
int main()
{
	while(1)
	{
	cout<<"\nenter operation\t";
	int op;
	cin>>op;
	if(op==4)
		return 0;
	else if(op==1)
	{
		cout<<"\nenter element to push\t";
		int x;
		cin>>x;
		pushit(x);
	}
	else if(op==2)
	{
		cout<<"\nminelement\t"<<minele();
	}
	else if(op==3)
	{
		cout<<popit()<<"\n";
		//printtop();
	}
}
	
}