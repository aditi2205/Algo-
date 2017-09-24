#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	stack<char> st;
	string s;
	cin>>s;
	int red=0,count;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]!=')')
			st.push(s[i]);
		
		else if(s[i]==')')
		{
			 count=0;
			 if(st.empty())
			 	{cout<<"Invalid parenthesis";
			        i++;}
			while( !st.empty()&&st.top()!='(' )
			{
				st.pop();
				count++;
			}
		
		st.pop();
		if(count<2)
		{
			red+=1;
		}
		}
	}
	cout<<red;
}