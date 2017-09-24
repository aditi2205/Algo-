#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct paira
{
	int min;
	int max;
};
//finding minium and maximum element using divide and conquer
struct paira tournament(vector<int> a,int low,int high)
{
	struct paira minmax;
	if(high==low)
	{
		minmax.min= a[low];
		minmax.max= a[low];
		return minmax;
	}
	else if(high==(low-1))
	{
		if(a[low]<a[high])
		{
			minmax.max= a[high];
			minmax.min= a[low];
		}
		else
		{
			minmax.min= a[high];
			minmax.max= a[low];
		}
		return minmax;
	}
			struct paira mm, mr;
		int mid= (low+high)/2;
		mm= tournament(a,low,mid);
		mr= tournament(a,mid+1,high);

		if(mm.min<mr.min)
		{
			minmax.min= mm.min;
		}
		else
			minmax.min= mr.min;

		if(mm.max>mr.max)
		{
			minmax.max= mm.max;
		}
		else
			minmax.max= mr.max;

		return minmax;

	
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

   struct paira m;
   m= tournament(a, 0, a.size()-1);

   cout<<m.max<<"\n"<<m.min;
}