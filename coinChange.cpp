#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int arr[]= {1, 3, 5, 6};
int n=4;

int change(int val, int* memo)
{
	/*if(val==0)
		return 0;
	if(val<0)
	{
         return 999999
;	}
	int res= 99999;
	for(int i=0; i<n; i++)
	{
		int rem= change(val-arr[i]);
		int cur = rem+1;
		res= min(res, cur);
	}
	return res;*/
	//TOP DOWN APPROACH:: COMPEXITY IS nV but this is not true dp and function overhead due to recursive call
	if(val==0)
	{
		return memo[val]=0;
	}

	if(val<0)
		return 9999;// to make invalid cases no effect on result

	if(memo[val]!=-1)
		return memo[val];
int res= 99999;
for(int i=0; i<n; i++)
	{
		int rem= change(val-arr[i], memo);
		int cur = rem+1;
		res= min(res, cur);
	}

	memo[val]= res;
	return memo[val];
}
int change1(int val)
{
	//bottom up
	int * memo= new int[val+1]();
	for(v=1; v<=val; ++v)
	{
		for(int i=0; i<n && arr[i]<=val; ++i)
		{
			int coins= memo[val- arr[i]]+1;
			memo[v]= min(memo[v], coins);                                                                                                      
		}
	}

}
int main()
{

int val;
cin>>val;
	int * memo= new int[val+1];
	memset(memo, -1, 4*(val+1));
	cout<<change(val,memo);
}