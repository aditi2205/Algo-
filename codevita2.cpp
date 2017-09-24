#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int findmin(int a[], int n)
{
	int min=a[0];
	int pos=0;
	for(int i=1; i<n; i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			pos=i;
		}
	}
	return pos;
}
int findmax(int a[], int n)
{
	int max=a[0];
	int pos=0;
	for(int i=1; i<n; i++)
	{
		if(a[i]> max)
		{
			max=a[i];
			pos=i;
		}
	}
	return pos;
}
bool checkposneg(int b[], int n)
{
	bool flag= false;
	for(int i=0; i<n; i++)
	{
		if(b[i]<0)
		{
			flag= true;
			break;
		}
	}
return flag;
}

int minprodsum(int a[], int k, int pos, int dec, int n, int b[])
{
	if(dec==0)
	{
		a[pos]= a[pos]+(2*k);
	}
	else
	{
		a[pos]= a[pos]-2*k;
	}
	int minsum=0;
	for(int i=0; i<n; i++)
	{
		minsum+= (a[i]*b[i]);
	}
	return minsum;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n], b[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int j=0; j<n; j++)
		cin>>b[j];

	bool flag=checkposneg(b,n);
	int dec=0,pos;
	if(flag==true)
	{
		 pos= findmin(b,n);
		 dec= 0;
	}
	else
	{
		pos= findmax(b,n);
		dec=1;
	}

	cout<< minprodsum(a,k,pos,dec,n,b);
	return 0;
}