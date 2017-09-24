#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> stockspan(vector<int>v, stack<int>& s)
{
	vector<int> ans;
	for(int i=0; i<v.size();i++)
	{
		int element= v[i];
		if(s.empty())
		{
			
			ans.push_back(0);
			s.push(i);
		}
		else
		{
			if(v[s.top()]>=element)
			{

				ans.push_back(abs(i-s.top()));
				s.push(i);
			}
			else
			{

			
				while(!s.empty() && v[s.top()]<element)
					s.pop();

				if(!s.empty())
				{
					ans.push_back(abs(i-s.top()));
				    s.push(i);
				}

			}
		}
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	stack<int> s;
	vector<int> v;
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
    vector<int> sol=stockspan(v,s);
    for(int i=0; i<sol.size(); i++)
    	cout<<sol[i]<<" ";

	
}