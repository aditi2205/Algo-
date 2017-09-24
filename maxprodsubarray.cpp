#include <iostream>
#include <numeric>
using namespace std;

int maxprod(int arr[], int n)
{
	int table[n][n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			table[i][j]=0;
	}

	//table[0][0]=arr[0];
	//table[n-1][n-1]= arr[n];

	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			if(j==i)
				table[i][j]= arr[i];
			/*if(j==i+1)
				table[i][j]= arr[i]*arr[j];*/
			else
				table[i][j]= table[i][j-1]*arr[j];
		}
	}

	/*for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<table[i][j]<<" ";

		cout<<endl;
	}*/
	int maxi= INT_MIN;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			{
				if(maxi<table[i][j])
					maxi= table[i][j];
		}
	}
	return maxi;
}


int main()
{
	int arr[]= {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<maxprod(arr, n);


}