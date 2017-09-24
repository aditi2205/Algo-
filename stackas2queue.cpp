#include<iostream>
#include<bits/stdc++.h>
using namespace std;
queue<int>q1;
queue<int>q2;

void pushit(int x)
{
	if(q1.empty())
		{q1.push(x);
			while(q2.empty()==false)
			{
				int ele= q2.front();
				q2.pop();
				q1.push(ele);
			}
		}
	else
	{
		q2.push(x);
		while(!q1.empty())
		{
			int ele= q1.front();
			q1.pop();
			q2.push(x);
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
	else if(!q2.empty())
	{

		int ele= q2.front();
		q2.pop();
		return ele;
	
	}
	else
		return -1;
}
int main()
{
	while(1)
	{
	cout<<"enter operation";
	int op;
	cin>>op;
	if(op==3)
		return 0;
	if(op==1)
	{
		cout<<"enter element to push";
		int x;
		cin>>x;
		pushit(x);
	}
	else
	{
		cout<<popit();
	}
}
	
}