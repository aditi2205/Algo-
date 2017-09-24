#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool checkop(char c)
{
	if(c>='a' && c<='z' )
		return 1;
	return 0;
}
int main()
{
	stack<char> st;
	string s;
	cin>>s;
	int red=0;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='(' || checkop(s[i]))
		{
			st.push(s[i]);
		}
		if(s[i]==')')
		{
			int count=0;
			while(st.top()!='(')
			{
				st.pop();
				count++;
			}
		}
		st.pop();
		if(count<2)
		{
			red+=1;
		}
		
	}
	cout<<red;
}