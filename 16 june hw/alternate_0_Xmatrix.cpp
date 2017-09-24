//Create a matrix with alternating rectangles of O and X
//Write a code which inputs two numbers m and n and creates a matrix of size m x n (m rows and n columns) in which every elements is either X or 0. 
//The Xs and 0s
// must be filled alternatively, the matrix should have outermost rectangle of Xs, then a rectangle of 0s, then a rectangle of Xs, and so on.


#include<iostream>
using namespace std;
const int n=8;
const int m=8;

void print(char a[n][m])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout<<a[i][j]<<" ";

		cout<<"\n";
	}
	
}
void zerox( char a[n][m])
{
    int t=0, b=n-1, r=m-1, l=0;
	int d=0;
	char ch='x';
	while(l<=r && t<=b)
	{
		if(d==0)
		{
			for(int i=l; i<=r; i++)
			{
				a[t][i]=ch;
			}
			t++;
		}
		else if(d==1)
		{
			for(int i=t; i<=b; i++)
			{
				a[i][r]=ch;
			}
			r--;
		}
		else if(d==2)
		{
			for(int i=r; i>=l; i--)
			{
			   a[b][i]=ch;
			}
			b--;
		}
		else if(d==3)
		{
			for(int i=b; i>=t; i--)
			{
				a[i][l]=ch;
			}
				l++;
		}



		d= (d+1)%4;
		if(d==0)
		{
			if(ch=='x')
				ch='0';
			else if(ch=='0')
				ch='x';
		}
	}

    

    print(a);
}
int main()
{
	
	char a[n][m];
	
	zerox(a);
	
}