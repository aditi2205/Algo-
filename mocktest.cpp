#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printpair(int a[][m], int n, int m)
{
	int table[n+1][m+1];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			table[i][j]=0;
		}
	}
	table[0][0]= a[0][0];
	int maxdiff= INT_MIN;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(i==0 && j==0)
				continue;
			if(i-1>=0 && j-1>=0)
			{
			     int diff= a[i][j]- a[i-1][j-1];
			     maxdiff= max(maxdiff, diff);
				table[i][j]= min(min(a[i-1][j], a[i][j]), min(a[i][j-1], a[i-1][j-1]));
			}
			else if(i-1>=0)
			{
				table[i][j]= min(a[i][j], a[i-1][j]);
			}
			else if(j-1>=0)
			{
				table[i][j]= min(a[i][j], a[i][j-1]);
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n";
	cout<<maxdiff;
}

int main()
{
	int n;
	cout<<"enter m and n\t";
	cin>>n;
	int m;
	cin>>m;
	int a[n][m];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>a[i][j];
		}
	}
	printpair(a,n,m);
}