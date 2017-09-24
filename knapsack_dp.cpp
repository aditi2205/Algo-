#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void knapsack(vector<pair<int, int> > v, int capacity, int n)
{
	
	int table[capacity+1][n+1];

	
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=capacity; j++)
		{
			if(i==0 || j==0)
				{  //cout<<"\ni or j is 0\n";
					table[i][j]=0;}
			//v[j].first= weight of the item
			else if(v[i-1].first>j)
			{
				//cout<<"\n"<<v[i-1].first<<"is greater than"<<j<<"n";
				table[i][j]= table[i-1][j];
			}
			else
			{
				//cout<<"\n table[i-1][j] is "<<table[i-1][j]<<"  table[i-1][j-v[i].first]+v[i].second  "<<table[i-1][j-v[i-1].first]+v[i-1].second<<"n";
				table[i][j]= max(table[i-1][j],  table[i-1][j-v[i-1].first]+v[i-1].second);
			}
		}
	}	

	/*for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=capacity; j++)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}*/
cout<<table[n][capacity];
}

int main()
{
	int capacity, n;
	cin>>capacity>>n;
	vector<pair<int, int> >v;
	// first: weight and second is value
	for(int i=0; i<n; i++)
	{
		int wt,val;
		cin>>wt>>val;
		v.push_back(make_pair(wt, val));
	}

	knapsack(v, capacity, n);

}