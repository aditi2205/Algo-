#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void swap(char *a, char *b)
{
	int temp= *a;
	*a= *b;
	*b= temp;
}
int checkbalanced(string s)
{
	stack<char> st;
	for(int i=0; i<s.size(); i++)
	{
		if( !st.empty() && s[i]==')')
		{
			if(st.top()=='(')
				st.pop();
			
		}
		else
	     st.push(s[i]);
	}
	if(st.empty())
		return 1;
	else
		return 0;
}
void minswap(char s[], int n)
{
	stack<char> st;
	for(int i=0; i<n; i++)
	{
		if (s[i]==')' && !st.empty())
        {
            if (st.top()=='(')
                st.pop();
            else
                st.push(s[i]);
        }
        else
            st.push(s[i]);
		
			
	}

	
	int t= st.size();
	int n1=0;
	string ss;
	while(!st.empty())
	{
		ss.push_back(st.top());
		st.pop();
	}
	reverse(ss.begin(), ss.end());
	//cout<<ss;
		int counts=0;

    
	while(true)
	{  
		int check= checkbalanced(ss);
		if(check==1)
			break;
	   for(int i=0; i<ss.size(); i++)
	   {

		int j= i+1;
		if(j<ss.size())
		{
			
			if(ss[i]==')' && ss[j]=='(')
			{
				//cout<<"\n string "<<ss<<" \n";
				//cout<<"\n"<<i<<" "<<j<<"\n";
				swap(&ss[i], &ss[j]);
				counts++;
				//flag= true;
			}
			
		}
	   }
	
	int check1= checkbalanced(ss);
	if(check==1)
		break;
	

}
	cout<<counts;

}
int main()
{
	int n;
	cin>>n;
	int len= 2*n;
	char s[len+1];

	cin>>s;
	minswap(s, len);
}