#include<iostream>
using namespace std;
const int n=3;
const int m=3;

void print(int a[n][m])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout<<a[i][j]<<" ";

		cout<<"\n";
	}
	
}
void rotate( int a[n][m])
{
    for(int layer=0; layer<n/2; layer++ )
    {
    	int first= layer;
    	int last= n-layer-1;
    	for(int i=first; i<last; i++)
    	{
    		int top= a[layer][i];
    		a[layer][i]= a[i][last];
    		a[i][last]= a[last][n-i-1];
    		a[last][n-i-1]= a[n-i-1][layer];
    		a[n-i-1][layer]= top;
    	}
    }

    print(a);
}
int main()
{
	
	int a[n][m];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cin>>a[i][j];
	}
	cout<<"\n";
	rotate(a);
	
}