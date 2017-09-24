#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cin>>a[i][j];
	}
	int col= m-1;
	int pos = -1;
	for(int p=0; p<m; p++)
	{
		//if value at all columns is same then we have our answer
		//find minimum in all rows in last column
		//decrement index of all others
		 			/*{1, 2, 3, 4, 5},   1,1 2,1 3,1 4,1 5,2
                    {2, 4, 5, 8, 10},
                    {3, 5, 7, 9, 11},
                    {1, 3, 5, 7, 9},*/
		int val= a[0][col];
		bool flag= true;

		for(int i=1; i<n; i++)
		{
			if(i==pos && pos!=-1)
			{
				if(col+1<m && a[i][col+1]!=val)
				{
					flag= false;
					break;
				}
			}
			else if(a[i][col] !=val)
			{
				flag= false;
				break;
			}

		}
		if(flag==true)
		{
			cout<<"found";
			cout<<val;
			return 0;
		}
		int minval=INT_MAX;
	    
		for(int i=0; i<n; i++)
		{
			if(i==pos && pos!=-1)
			{
				if(col+1<m && a[i][col+1] < minval)
				{
					minval= a[i][col+1];
					pos= i;
				}
			}
			else if(a[i][col] < minval)
			{
				minval= a[i][col];
				pos= i;
			}

		}
		
		if(col>0) col--;


	}
}