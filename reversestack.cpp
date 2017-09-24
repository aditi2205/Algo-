#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertatbottom(stack<int>& s, int cur)
{

	if(s.empty())
	{
		s.push(cur);
		return;
	}
	int x= s.top();
	s.pop();
	insertatbottom(s,cur);
	s.push(x);
}
void insertsorted(stack<int>&s, int x)
{
	if(s.empty())
	{
		s.push(x);
		return;
	}
	if(!s.empty() && s.top()<x)
	{
		s.push(x);
	}
	else if(!s.empty() && s.top()>x)
	{
		int ele= s.top();
		s.pop();
		insertsorted(s,x);
		s.push(ele);
	}

}
void sortstack(stack<int>&s)
{
	if(s.empty()) return;

	int cur= s.top();
	s.pop();
	sortstack(s);
	insertsorted(s, cur);
}
void reversestack(stack<int>& st)
{
	if(st.empty())
		return;
	int cur= st.top();
	st.pop();
	reversestack(st);
	insertatbottom(st,cur);
	}

int main()
{
	stack<int> st;
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	  {
	  	int x;
	  	cin>>x;
	  	st.push(x);
	  }

	  //reversestack(st);
	  sortstack(st);
	  while(!st.empty())
	  {
	  	int cur= st.top();
	  	cout<<cur<<" ";
	  	st.pop();
	  }
	
}