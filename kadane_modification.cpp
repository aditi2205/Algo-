#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int kadanerecursive(int arr[], int index,int n, int sum, int maxsum)
{
	if(index>n)
		return 0;
	
	int ans= kadanerecursive(arr, index+1, n, sum-arr[index], maxsum);
	int ans2= kadanerecursive(arr, index+1, n, sum, maxsum);

	if(ans>ans2)
		maxsum= max(ans, maxsum);
	else
		maxsum= max(ans2, maxsum);

	return maxsum;

}
int main()
{
	/*int arr[]= {-2, -3, 4, -1, -2, 1, 5, -3};

	int n= sizeof(arr)/ sizeof(arr[0]);*/
	int arr[] = {5, 5, 10, -100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
	int sum=0;
	for(int i=0; i<n; i++)
		sum+=arr[i];
    cout<<sum<<"\n";
	int maxsum=kadanerecursive(arr,0 , n , sum, sum);
	cout<<maxsum;
}