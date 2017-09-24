#include <iostream>

#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(vector<int>&a, int low, int high)
{
  int i= low-1;
  int pivot= a[high];
  
  for(int j=low; j<=high-1; j++)
  {
    if(a[j]<=pivot)
    {
      i++;
      swap(&a[i], &a[j]);
      
    }
  }
  swap(&a[i+1], &a[pivot]);
  return (i+1);
}
/*int randompartition(vector<int> &a, int low, int high)
{
  int n= (high-low+1);
  int pivot= (rand()%n);

  swap(a[low+pivot], a[high]);
   cout<<pivot<<"\n";
  return partition(a, low, high);
}*/
void quicksort(vector<int>&a , int low, int high)
{
   if(low<=high)
   {
     int index=partition(a, low, high);
     //cout<<index;
     quicksort(a, low, index-1);
     quicksort(a, index+1, high);
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

 quicksort(a,0,n-1);

 for(int i=0; i<n; i++)
  cout<<a[i]<<" ";
 }