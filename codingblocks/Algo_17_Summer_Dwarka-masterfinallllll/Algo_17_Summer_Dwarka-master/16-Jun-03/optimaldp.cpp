#include <iostream>
#include <numeric>
using namespace std;

void optimalgame(int arr[], int n)
{
	int table[n][n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			table[i][j]=0;
	}

	for(int i=0;i<n; i++)
	{
		table[i][i]= arr[i];
	}

  int k= n-1;
  int m= 1;
  int c=1;
	for(int i=0; i<n-1; i++)   // number of times loop will be running
	{
		for(int j=0; j<k; j++)
		{
			if(c==1)
			table[j][j+c] = max(table[j][j], table[j+c][j+c]);
		    else
		    {
		    	table[j][j+c]= max(  arr[j]+min(table[j+2][j+c], table[j+1][j+c-1])  ,  arr[j+c]+min(table[j+1][j+c-1], table[j][j+c-2]) );
		    }
		}
		c++;
		k--;
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<table[i][j]<<" ";
		cout<<endl;
	}
	cout<<table[0][n-1];

	
}


int main()
{
	int arr[]= {5, 3, 7, 10};
	int n= sizeof(arr)/sizeof(arr[0]);
	optimalgame(arr, n);


}