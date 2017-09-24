#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;

void findsum(vector<int> cur, int index, int target, int cursum)
{
	vector<int> curr;
	if(cursum>target)
		return;
	if(cursum==target)
	{
		ans.push_back(curr);
	}
	if(index>=cur.size())
		return;
	
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
   int sum;
   cin>>sum;
    findsum(a,0,sum);
   }