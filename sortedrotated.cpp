#include<iostream>
using namespace std;

int search(int a[], int low,int high, int x)
{
	while(low<=high)
	{
        int mid= (low+high)/2;
        if(a[mid]==x)
        {
              return mid;
        }
        else if(a[mid]<x)
        {
            if(a[mid]<=a[high])
            {
            	if(x>a[mid] && x<=a[high])
            		low= mid+1;
            	else
            		high= mid-1;
            }
            else
            	high= mid-1;
        }
        else if(a[mid]>x)
        {
        	if(a[low]<=a[mid])
        	{
        		if(x>=a[low] && x<a[mid])
        			high= mid-1;
        		else
        			low=mid+1;
        	}
        	else
        		low= mid+1;
        }
	}
	return -1;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
   int n;
   cout<<"element to search";
   cin>>x;
	int val=search(a,0,n-1,x);
	cout<<val;
}