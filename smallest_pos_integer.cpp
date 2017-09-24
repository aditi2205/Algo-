#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int *a= new int[n+1];
	for(int i=0; i<n; i++)
		cin>>a[i];

	int res=a[0], sum=0,i, prevsum;
	for(i=0; i<n; i++)
	{

		int val= a[i];
		prevsum= sum;
		sum+=a[i];
		cout<<val<<" "<<sum<< " "<<res<<"\n";
		if(res==val || res==sum || res==prevsum)
		{
			res++;
			continue;
		}
		break;

	}
	if(i!=n)
		cout<<res;
	else
		cout<<sum+1;
}