#include <iostream>
#include<numeric>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

void twicetwo(vector<int> a)
{
    int x=0;
    for(int i=0; i<a.size(); i++)
    	x= x^a[i];

    int pos= log2(x&-x)+1;
    pos= pos-1;

    int mask= pow(2,pos);

    int ans=0;

    for(int i=0; i<a.size(); i++)
    {
    	int v1=(mask&a[i]);
    	if(v1==mask)
    		ans= ans^a[i];

    }

    cout<<"1st"<<ans<<"\n";
    int ans1= ans^x;
    cout<<"2nd"<<ans1;

}
int main() {
   int n;
   cin>>n;
   vector<int> a;
   for(int i=0; i<n; i++)
   {
       int x;
       cin>>x;
       a.push_back(x);
   }
   twicetwo(a);
 }
