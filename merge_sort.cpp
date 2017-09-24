#include<iostream>
using namespace std;
void merge(int a[], int low, int high)
{
	int mid= (low+high)/2;

	int left[mid-low+1];

	int right[high-mid];

	for(int i=0; i<mid-low+1; i++)
		left[i]=a[i+low];
	
	for(int i=0; i<high-mid; i++)
		right[i]= a[i+mid+1];
	int p=0, q=0, k=low;
	while(p<mid-low+1 && q<high-mid)
	{
		if(left[p]<=right[q])
		{
			a[k]= left[p];
			p++;
			k++;
		}
		else
		{
			a[k]=right[q];
			q++;
			k++;
		}
	}
	while(p<mid-low+1)
		a[k++]=left[p++];
	while(q<high-mid)
		a[k++]=right[q++];
}
void mergesort(int a[], int low, int high)
{
      int mid= (low+high)/2;
      if(low<high)
      {
      mergesort(a, low, mid);
      mergesort(a, mid+1,high);

      merge(a, low, high);
  }
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
    mergesort(a, 0, n);
    for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
}