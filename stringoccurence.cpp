#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void findstring(vector<string>v, vector<char> c)
{
	map<char, bool> se;
	vector<pair<string, pair<int, int> > > v1;
	for(int i=0; i<c.size(); i++)
		se.insert(make_pair(c[i], false));
	for(int i=0; i<v.size(); i++)
	{
		int cnt=0, cnt1=0;
		for(int j=0; j<v[i].size(); j++)
		{
			
			if(se.find(v[i][j])!=se.end() )
			{
				if(se[v[i][j]]!=true)
				{cnt++;
				se[v[i][j]]= true;
				}
				cnt1++;
			}
		}
		v1.push_back(make_pair(v[i], make_pair(cnt, cnt1)));
		map<char, bool>::iterator it;
		for(it=se.begin(); it!=se.end(); it++) 
			it->second= false;
	}
	int maxc=v1[0].second.first;
	int maxcc= v1[0].second.second;
	string ans= v1[0].first;
	for(int i=1; i<v1.size(); i++)
	{
		cout<<v1[i].first<<" "<<v1[i].second.first<<" "<<v1[i].second.second<<"\n";
		if(v1[i].second.first>maxc)
		{
			maxc= v1[i].second.first;
			maxcc= v1[i].second.second;
			ans= v1[i].first;
		}
		else if(v1[i].second.first==maxc)
		{
			if(maxcc<v1[i].second.second)
			{
				maxc= v1[i].second.first;
				maxcc= v1[i].second.second;
				ans= v1[i].first;
			}
		}
	}
	cout<<ans;	
}
int main()
{
	vector<string> s;
	vector<char> c;
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		string a;
		cin>>a;
		s.push_back(a);
	}
	for(int i=0; i<m; i++)
	{
		char a;
		cin>>a;
		c.push_back(a);
	}
	findstring(s,c);
}