#include<iostream>
#include<bits/stdc++.h>
using namespace std;
map<int, int> m;
void takeinput(vector<int> a)
{
	int n;
	cout<<"ENtre size";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
}
bool compare(int a, int b)
{
/*if(m.find(a)==m.end() || m.find(b)==m.end())
		return 0;
	if(m[a]>=0 && m[b]>=0)
	return (m[a]<m[b])?1:0;*/
	if(m[a]&&m[b]){
		return (m[a]<m[b]);
	
	if(m[a])
		return 1;
	if(m[b])
		return 0;
	return a<b;
}
}
int main()
{
	vector<int> a;
	vector<int> b;
	int n;
	cout<<"ENtre size";
	cin>>n;
	for(int i=0; i<n; i++)
	{  int x;
		cin>>x;
		a.push_back(x);
	}
	int n1;
	cout<<"ENtre size";
	cin>>n1;
	for(int i=0; i<n1; i++)
	{
		int x;
		cin>>x;
		b.push_back(x);
	}

	
	for(int i=0; i<b.size(); i++)
	{
		if(m.find(b[i])==m.end())
		{
			m.insert(make_pair(b[i], i+1));
		}
	}

	sort(a.begin(), a.end(), compare);
	for(int i=0; i<a.size(); i++)
	{
		cout<<a[i]<<" ";
	}

}