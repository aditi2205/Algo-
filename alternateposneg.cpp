#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void rightrotate(int a[], int pos, int index, int n)
{
	int temp= a[index];
	for(int i=index; i>pos; i--)
		{
			a[i]= a[i-1];
		}
		a[pos]= temp;
}
void printposneg(int a[], int n)
{
	//find first out of place element
	int p=0;
	while(p<n)
	{
	int pos=-1;
	for(int i=p; i<n; i++)
	{
		if((i%2==0 && a[i]>=0) || (i%2==1 && a[i]<0))
		{
			pos=i;
			break;
		}
	}
	if(pos!=-1)
	{
		cout<<"POS1"<<pos<<"\n";
		//find next opposite sign element
		int sign= 0;//negative
		int pos2=-1;
		if(a[pos]>0) sign=1;//positive

		for(int j= pos+1; j<n; j++)
		{
			if((sign==1 && a[j]<0)||(sign==0 && a[j]>=0))
			{
				pos2=j;
				break;
			}
			
		}

       if(pos2!=-1)
       {  cout<<"POS2"<<pos2<<"\n";
       	 rightrotate(a, pos, pos2, n);
       	 for(int i=0; i<n; i++)
			 cout<<a[i]<<" ";
		cout<<endl;
       }

       p= pos2+1;

	}
}


	

for(int i=0; i<n; i++)
 cout<<a[i]<<" ";
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];

	printposneg(a,n);
}