#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool comp(string a, string b)
{
	return (a.size()<b.size());
}
int main()
{
  vector<string> v;
  int n;
  cin>>n;
  for(int i=0; i<n; i++)
  {   string b;
  	cout<<"enter string:"<<endl;
  	  cin>>b;
  	  v.push_back(b);

  }
  sort(v.begin(), v.end(), comp);
  for(int i=0; i<v.size(); i++)
  	cout<<v[i]<<" ";
}