#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printmax(long a[], long n, long k)
{
	deque<long> q(k);
	long i;
	for( i=0; i<k; i++)
	{
		
			
		while(!q.empty() && a[q.back()]<a[i])
			q.pop_back();
		q.push_back(i);

	}

	for(; i<n; i++)
	{
		cout<<a[q.front()]<<" ";

		while(!q.empty() && (q.front())<(i-k+1))
			q.pop_front();
        while(!q.empty() && a[q.back()]<=a[i])
        	q.pop_back();
        q.push_back(i);
	}
	cout<<a[q.front()];
}

int main()
{
	long n;
	cin>>n;
	long a[n];
	for(long i=0; i<n; i++)
	{
		cin>>a[i];
	}
	long k;
	cin>>k;
	printmax(a,n,k);
}