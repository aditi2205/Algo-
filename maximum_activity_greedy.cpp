#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.second!=b.second ? a.second<b.second: a.first<b.first;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pair<int, int> >v;
		for(int i=0; i<n; i++)
		{
			int start, finish;
			cin>>start>>finish;
			v.push_back(make_pair(start, finish));

		}

		sort(v.begin(), v.end(), comp);
		/*for(int i=0; i<v.size(); i++)
		{
			cout<<v[i].first<<" "<<v[i].second<<"\n";
		}*/
		int c=1;
		int checker= v[0].second;
		for(int i=0; i<v.size()-1; i++)
		{
			if(checker<=v[i+1].first)
				{
					c++;
					checker= v[i+1].second;
				}

		}
		cout<<c<<"\n";
	}
	/*	map<int, int> hash;
		for(int i=0; i<n; i++)
		{
			int start, finish;
			hash.insert(make_pair(start, finish));

		}
		bool comp= [](pair<int, int> const &a, pair<int, int> const &b)
		{
			return a.second!=b.second? a.second<b.second: a.first<b.first;
		};
		sort(hash.begin(), hash.end(), comp);

		map<int, int>::iterator it;
		int c=0;
		for(it= hash.begin(); it!=hash.end(); it++)
		{
			cout<<it->first<<" "<<it->second<<"\n";
			int a= (it)->second;
			int b= (it)->first;
			if(a<=b)
				c++;

		}
		cout<<c<<"\n";*/
		
	
}