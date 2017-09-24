#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int canpossible(vector<int> a, int value, int n, int st)
{
	int s=1;
	int maxpages=0;
	for(int i=0; i<n; i++)
	{

		if(a[i]>value)
			return 0;

		else if(a[i]+maxpages<=value)
			maxpages= maxpages+a[i];

		else
		{
			maxpages= a[i];
			++s;
			if(s>st)
				return false;
		}
	}
	return true;
}

int findpages(vector<int> a, int n, int st)
{
	int maxsum=0;
	for(int i=0; i<n; i++)
		maxsum+=a[i];

	int low=0;
	int high= maxsum;
	while(low<=high)
	{
		int mid= (low+high)/2;

		if(canpossible(a,mid,n,st))
		{
			maxsum= min(mid, maxsum);
			high= mid-1;
		}
		else
		{
			low= mid+1;
		}
	}
	return maxsum;
}
int main() {
	int n, k;
   cin>>n>>k;
   vector<int> a;
   
   for(int i=0; i<n; i++)
   {
       int x;
       cin>>x;
       a.push_back(x);
   }

   int ans= findpages(a, n, k);
   cout<<ans;
}
/*
#include <iostream>
#include <numeric>
using namespace std;




int minPages(int pages[], int n, int students){
	int maxPages = accumulate(pages, pages + n, 0);	//sum of pages 
	int low = 0;
	int high = maxPages;
	//single student will be given all pages to read...poor chap!
	//the answer, that is, the minimum no of possible pages that shall be given to each
	//student, will definitely lie between [low, high]

	while(low <= high){
		int mid = (low + high) / 2;
		//can mid be the required answer
		if (canPossible(pages, students, mid, n)){
			//Oh yes! it is..lets choose the minimum of cur or the bestSoFar
			maxPages = min(maxPages, mid);
			
			//lets try the next possible solution
			high = mid - 1; 
		}
		else {
			low = mid + 1;
		}
	}

	return maxPages;
}



int main(){
	int arr[] = {12,34,67,90};
	int n = sizeof(arr) / sizeof(int);

	int students;
	cin >> students;

	int ans = minPages(arr, n, students);
	cout << ans;
}*/