#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxareahistogram(vector<int> a)
{
	
	int n= a.size();
	int i=0;
	stack<int> s;
	int area=0, maxarea=INT_MIN;
	
	while(i<n)
	{
		
	 if(s.empty() || a[s.top()]<= a[i])
	 {
	 	s.push(i);
	 	i++;
	 }
	 else
	 {
	 	
	 		int v= s.top();
	 		s.pop();
	 		if(s.empty())
	 		{
	 			area= a[v]*i;
	 		}
	 		else
	 		{
	 			area= a[v]*(i-v);
	 		}
	 		if(maxarea<area)
	 			maxarea= area;
	 	}
	 
	}
	while(!s.empty())
	 	{
	 		int v= s.top();
	 		s.pop();
	 		if(s.empty())
	 		{
	 			area= a[v]*i;
	 		}
	 		else
	 		{
	 			area= a[v]*(i-v);
	 		}
	 		if(maxarea<area)
	 			maxarea= area;
	 	}


	return maxarea;
}


	
	
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}

	cout<< maxareahistogram(a);
}