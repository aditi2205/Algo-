#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findsum(vector<int> a, vector<int>b, int n, int m)
{
    int result[n+m];
    int size;
    if(n==m)
    {
        size=m+1;
    }
    else if(n<m) size=m+1;
    else size=n+1;

    int i=n, j=m;
    int carry=0;
  int k=size;
    while(i>=0 || j>=0)
    {
    	int val= ((i>=0)?a[i]:0)+((j>=0)?a[j]:0)+carry;
    	if(val>=10)
    	{
    		val=val%10;
    		carry=1;
    	}
    	result[k--]=val;

       i--;
       j--;
    }

    for(int i=0; i<size; i++)
    	cout<<result[i]<<" ";

}
int main() {
    int n,m;
    vector<int> a;
    vector<int> b;
    cin>>n;
    for(int i=0; i<n; i++)
    {
    	int x;
    	cin>>x;
    	a.push_back(x);
    }
     cin>>m;
     for(int i=0; i<m; i++)
    {
    	int x;
    	cin>>x;
    	b.push_back(x);
    }

    findsum(a,b,n,m);

}
