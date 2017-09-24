#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int isprime(int n)
{
	for(int i=2; i<=sqrt(n); i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}
int makeprimearray(vector<int> &a, int n)
{
	if(n<1)
		return 0;
	a.push_back(2);
	int j=1;
	int val=2;
	int count=0;
	for(int i=3; i<n; i++)
	{
		if(isprime(i))
			{   val= val+i;
				if(val<=n)
			      {
			      	if(isprime(val))
			      	{  
			      		count++;
			      	}
			      }
		}
	}
	/*for(int i=1; i<a.size(); i++)
		{
			a[i]=a[i]+a[i-1];
		}
		
		
	for(int i=1; i<a.size(); i++)
	{
		if(isprime(a[i]))
			{
				if(a[i]<=n)
				{
				count++;
			}
			}
	}*/
	return count;
}

int main()
{
	int n;
	cin>>n;
	vector<int> a;
	cout<<makeprimearray(a,n);
	return 0;


}