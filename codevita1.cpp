#include<iostream>
#include<iomanip>
using namespace std;

void printpattern(int a[], int size, int n)
{
	
	int m=0;
	for(int i=0; i<n; i++)
	{    int k=0;
		int spaces= n-i-1;
		for(int j=0; j<spaces; j++)
			cout<<" ";
		
		while(k!=i+1)
		{
             cout<<setfill('0')<<setw(5)<<a[m++]<<" ";
             k++;
		}
		cout<<"\n";

	}
   
}
void constructarr(int a[], int size, int n)
{
	a[0]=6;
	a[1]=28;
	int d= 16;
	for(int i=2; i<size; i++)
	{
		int val= a[i-1]-a[i-2]+d;
		a[i]= a[i-1]+val;
	}
	//for(int i=0; i<size; i++)
	//	cout<<a[i]<<" ";
	printpattern(a,size,n);
}
int main()
{

	int n;
	cin>>n;

	int size= (n*(n+1))/2;

	int arr[size+1];

	constructarr(arr,size,n);
	return 0;
}