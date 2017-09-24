#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void LIS(int a[], int n)
{
	int *table= new int[n+1];
	for(int i=0; i<n; i++)
		table[i]=1;
	int maxi= INT_MIN;
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(a[j]<=a[i])
			{
				table[i]= max(table[i],table[j]+1);	
			}

		}
	}
int pos;
	for(int i=0; i<n; i++)
	{
		if(maxi<table[i])
			{maxi=table[i] ;
				pos=i;}
	}
	cout<<maxi<<"\n";

	int maxval= maxi;
	vector<int> ans;
	ans.push_back(a[pos]);
	for(int i= pos-1; i>=0; i--)
	{
		if(table[i]== maxval-1)
		{
			ans.push_back(a[i]);
			maxval= maxval-1;
		}
	}
	reverse(ans.begin(), ans.end());
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}

	LIS(a,n);
}