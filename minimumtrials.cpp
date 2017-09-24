#include <iostream>
#include <queue>
#include<bits/stdc++.h>
using namespace std;
int minimumtrials(int eggs, int floors)
{
	int mini=9999;
	if(floors==1 || floors==0)
		return floors;
	if(eggs==1)
		return floors;
	

	if(eggs>floors)
		return minimumtrials(eggs-1, floors);
	else
		{
			
			for(int k=1; k<=floors; k++)
			{
                int a= max(minimumtrials(eggs-1,k-1), minimumtrials(eggs, floors-k));
                if(a<mini)
                	mini=a;
			}
		}
		return mini+1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int floors, eggs;
		cin>>eggs>>floors;
		cout<<minimumtrials(eggs, floors);
	}
}