#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void reversequeue(queue<int>& q)
{
	if(q.empty())
		return;
	int ele= q.front();
	q.pop();
	reversequeue(q);
	q.push(ele);
}
int main()
{
	queue<int> q;
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	  {
	  	int x;
	  	cin>>x;
	  	q.push(x);
	  }
     reversequeue(q);
	 while(!q.empty())
	 {
	 	cout<<q.front()<<" ";
	 	q.pop();
	 }
	
}