#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void findpattern(char text[], char patt[], int n, int m)
{
	map<char, int> m, m1;
	for(int i=0; i<m; i++)
	{
		if(m.find(patt[i])!=m.end())
			m[patt[i]]++;
		else
			m.insert(make_pair(patt[i],1));
	}

	for(int i=0; i<n; i++)
	{
		m1 = m;
		for(int j=0; j<m; j++)
		{
			if(m1.find(text[j])!=m1.end())
				m1[text[j]]--;
		}
		map<char, int>::iterator it;
		int res;
		for(it=m1.begin(); it!=m1.end(); it++)
		{
			if(it->second!=0)
				{	res=-1;
					break;}
		}
		if(res!=-1)
			cout<<"found at: "<<i<<"\n";

	}
}
int main()
{
	int n,m;
	cin>>m>>n;
    char text[n+1], patt[m+1];
    cin>>text;
    cin>>patt;
    findpattern(text, patt, n, m);
}
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void findpattern(char text[], char patt[], int n, int m2)
{
	map<char, int> m;
	for(int i=0; i<m2; i++)
	{
		if(m.find(patt[i])!=m.end())
			m[patt[i]]++;
		else
			m.insert(make_pair(patt[i],1));
	}

	for(int i=0; i<n-k; i++)
	{
	    for(int j=0; j<k; j++)
	    {
	        
	    }
	}
}
int main()
{
	int n,m;
	cin>>m>>n;
    char text[n+1], patt[m+1];
    cin>>text;
    cin>>patt;
    findpattern(text, patt, n, m);
}