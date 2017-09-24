#include<iostream>
#include<bits/stdc++.h>
using namespace std;


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

	  reversestack(st);
	  while(!st.empty())
	  {
	  	int cur= st.top();
	  	cout<<cur<<" ";
	  	st.pop();
	  }
	
}