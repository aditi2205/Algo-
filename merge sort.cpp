#include<iostream>
#include<algorithm>
using namespace std;
void merge_sort(int a[], int low, int high)
{
	int mid= (low+high)/2;
	int l[mid+1];
	int h[high-mid+1];
	for(int i=low; i<mid; i++)
		l[i]=a[i];
	for(int i=mid; i<high; i++)
		h[i]= a[i];

	int j=0, k=0, m=0;
	while(j<mid && k<(high-mid+1))
	{
           if(l[j]<=h[k])
           {
           	a[m]=l[j];
           	m++;
           	j++;
           }
           else if(h[k]<l[j])
           {
           	a[m]=h[k];
           	k++;
           	m++;
           }


	}
	while(m<high && j<mid)
	{
		a[m]=l[j];
		m++;
		j++;
	}
	while(m<high && k<high-mid+1)
	{
		a[m]=h[k];
		m++;
		k++;
	}

	for(int i=0; i<high; i++)
		cout<<a[i]<<" ";
}
int main()
{
	int arr[10];
	for(int i=0; i<10; i++)
	{
		cin>>arr[i];
	}
	merge_sort(arr,0,10);
}