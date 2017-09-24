#include<iostream>
using namespace std;
const int n=3;
const int m=4;
void spiralprint( int a[n][m])
{
	int t=0, b=n-1, r=m-1, l=0;
	int d=0;
	while(l<=r && t<=b)
	{
		if(d==0)
		{
			for(int i=l; i<=r; i++)
			{
				cout<<a[t][i]<<" ";
			}
			t++;
		}
		else if(d==1)
		{
			for(int i=t; i<=b; i++)
			{
				cout<<a[i][r]<<" ";
			}
			r--;
		}
		else if(d==2)
		{
			for(int i=r; i>=l; i--)
			{
				cout<<a[b][i]<<" ";
			}
			b--;
		}
		else if(d==3)
		{
			for(int i=b; i>=t; i--)
			{
				cout<<a[i][l]<<" ";
			}
				l++;
		}



		d= (d+1)%4;
	}

}
int main()
{
	
	int a[n][m];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cin>>a[i][j];
	}
	spiralprint(a);
	
}