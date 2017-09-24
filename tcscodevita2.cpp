#include<iostream>
#include<string>
#include<stdlib.h>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;

long long readit(vector<string> temp, int n)
{
	//convert all the strings to their respective values keeping in mind the hanges
	long long sum=0;
	long long val=0;
	vector<string> num;
	string x;
	for(int i=0; i<n; i++)
	{
		x.clear();
		for(int j=0; j<temp[i].size(); j++)
		{
			
			if(temp[i][j]=='A') x.push_back('0');
			else if(temp[i][j]=='B') x.push_back('1');
			else if(temp[i][j]=='C') x.push_back('2');
			else if(temp[i][j]=='D') x.push_back('3');
			else if(temp[i][j]=='E') x.push_back('4');
			else if(temp[i][j]=='F')
			{
				if(j+1< (int)temp[i].size() && temp[i][j+1]=='E')
					x.push_back('4');
				else
					x.push_back('5');
			} 
			else if(temp[i][j]=='G')
			{
				if(j+1< (int)temp[i].size() && temp[i][j+1]=='D')
					x.push_back('3');
				else
					x.push_back('6');
			} 
			else if(temp[i][j]=='H')
			{
				if(j+1< (int)temp[i].size() && temp[i][j+1]=='C')
					x.push_back('2');
				else
					x.push_back('7');
			} 
			else if(temp[i][j]=='I')
			{
				if(j+1< (int)temp[i].size() && temp[i][j+1]=='B')
					x.push_back('1');
				else
					x.push_back('8');
			} 
			else if(temp[i][j]=='J')
			{
				if(j+1< (int)temp[i].size() && temp[i][j+1]=='A')
					x.push_back('0');
				else
					x.push_back('9');
			} 
		}
		num.push_back(x);
	}
	long long tempsum;
	for(int i=0; i<num.size(); i++)
	{
		stringstream integerval(num[i]);
		int x=0;
		integerval >> x;
		sum+=x;
			
		
	}

	return sum;
}
int main()
{
	int n;
	cin>>n;
	vector<string> v;
	for(int i=0; i<n; i++)
	{
		string temp;
		cin>>temp;
		v.push_back(temp);
	}
	long long reading;
	cin>>reading;
	long long total= readit(v,n);
	//cout<<total;
	if(total> reading)
		cout<<"GREEDY\n"<< (total-reading)<<"\n";
	else
		cout<<"INNOCENT\n";
}