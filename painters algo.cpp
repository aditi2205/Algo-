#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int checkpartition(vector<int>& a, int k, int checksum)
{
    int n = 1;// number of painters
    int sum=0,i;
    vector<int> ans;
    for( i=0; i<a.size(); i++)
    {   
        //if(sum<=checksum)
        if(a[i]>checksum)
            return 0;
        sum= sum+a[i];
        cout<<"SUM IS"<<sum<<"\n";
       if(sum>checksum)
        {

            n++;
            if(n>k)
            return 0;
            sum = a[i];
            cout<<"SUM IS GREATER: NEW SUM IS"<<sum<<"\n";
        }
        
    }

   return 1;
}

int paint(int k, int t, vector<int> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int sum=0;
    for(int i=0; i<a.size(); i++)
    {
        sum+=a[i];
    }
    cout<<sum<<"\n";
    int low= 0; int high= sum;
    int mini=sum;
    while(low<=high)
    {
        int mid= (low+high)/2;
        cout<<"mid is:"<<mid<<"\n";
        if(checkpartition(a,k,mid)!=0)
        {
            mini= min(mid,sum);
          
            high= mid-1;
        }
        else 
         low= mid+1;
    }
    
    return mini*t;
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> a;

    for(int i=0;i<n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    int k,t;
    cin>>k>>t;
    cout<<paint(k,t,a);
}