#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findprofit(int arr[], int be, int end,  int t)
{

	/*if(be>end)
     	return 0;

	if(t==1)
	{
		int v1= arr[be]*t;
		int v2= arr[end]*t;
		sum= max(v1, v2);
		return sum;
	}

     

		int ch1= findprofit(arr, be+2, end, t+1, (sum+arr[be+1])*t,n);
	int ch2= findprofit(arr, be+1, end-1, t+1, (sum+arr[end])*t,n);

	int res1= max(ch1, ch2);
    int ch11= findprofit(arr, be, end-2, t+1, (sum+arr[end-1])*t,n);
	int ch22= findprofit(arr, be+1, end-1, t+1, (sum+arr[be])*t,n);
	int res2= max(ch11, ch22);

	return max(res1, res2);*/
	if(be>en)
		return 0;
	if(memo[be][n]!=-1)
		return memo[be][en];
	int left= arr[be]*t + findprofit(be+1, en, t+1); //if we choose left side bottlle
	int right= arr[en]*t + findprofit(be, en-1, t+1);// if we choose right side bottle

	return memo[be][en] = max(left, right);


}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];

	findprofit(arr,0,n-1, 1,0);
}