#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
  int temp;
  temp=a;
  a=b;
  b=temp;
}

void sort(vector<int>&a , int n)
{
  int low=0, mid=0, high= n-1;

  while(mid<=high)
  {
    if(a[mid]==0)
    {
      swap(a[low], a[mid]);
      mid++;
      low++;
    }
    else if(a[mid]==1)
    {
      mid++;
    }
    else if(a[mid]==2)
    {
      swap(a[mid], a[high]);
      high--;
    }
  }
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

 sort(a,n);

 for(int i=0; i<n; i++)
  cout<<a[i]<<"\n";
 }