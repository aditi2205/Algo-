#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
	int t= a;
	a=b;
	b=t;
}
void minimumswap(int a[], int n)
{
	//minimum swap
	//number of nonzero
	int nonzero=0;
	int indexzero=-1, indexnon=-1;
	int count=0;
	int i1=0, j=n;
	for(int i=0; i<n; i++)
	{
		if(a[i]!=0)
			nonzero++;
	}
	while(i1<j)
	{
		//cout<<i1<<" "<<j<<"\n";
	for(int i=i1; i<j; i++)
	{
		if(a[i]==0)
			{indexzero=i;
				break;}
	}
	for(int i=j-1; i>=i1; i--)
	{
		if(a[i]!=0)
		{
			indexnon =i;
			break;
		}
	}
	//cout<<"\n "<<indexzero<<" "<<indexnon<<"\n";
	if(indexzero!=-1 && indexnon!=-1 && indexzero < indexnon)
	{
		swap(a[indexnon], a[indexzero]);
		for(int m=0; m<n; m++)
			cout<<a[m]<<" ";
		cout<<endl;
		count++;
	}

	i1=indexzero+1;
	j=indexnon;
	indexzero=-1;
	indexnon=-1;
}
cout<< count <<" "<< nonzero;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	minimumswap(a, n);
}

