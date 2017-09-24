#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findsubsequence(string str, string search)
{
	int n= str.size();
	int searchsize= search.size();
	int table[searchsize+1][n+1];

	for(int i=0; i<=searchsize; i++)
	{
		table[i][0]=0;
	}
	for(int i=0; i<=n; i++)
	{
		table[0][i]=0;
	}
	for(int i=1; i<=searchsize; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(search[i-1]== str[j-1] && (str[j]!=str[j-1]))
			{
				table[i][j]= max(table[i-1][j], table[i][j-1])+1;
			}
			else
			{
				table[i][j]= max(table[i-1][j], table[i][j-1]);
			}
		}
	}	

	for(int i=0; i<=searchsize; i++)
	{
		for(int j=0; j<=n; j++)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	return table[searchsize][n];
}

int main()
{
	string str;
	getline(cin, str, '\n');
	string search;
	cin>>search;
	cout<<"\n";
	cout<<findsubsequence(str, search);
}