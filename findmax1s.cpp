#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m;
	    cin>>n>>m;
	    int a[n][m];
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    int index;
	    int minindex= -1;
	    int finalindex= -1;
	    for(int i=0; i<n; i++)
	    {
	        int low=0;
	        int high= m;
	        while(low<high)
	        {
	            int mid= (low+high)/2;
	            if(a[i][mid]==1)
	            {
	                minindex= mid;
	                high= mid-1;
	            }
	            if(a[i][mid]<1)
	              low= mid+1;
	        }
	        
	        finalindex= min(finalindex, minindex);
	    }
	    
	}
	return 0;
}
