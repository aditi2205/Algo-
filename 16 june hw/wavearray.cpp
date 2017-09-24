#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0; i<n; i++)
		{
			int x;
			cin>>x;
			a.push_back(x);
		}

	/*sort(a.begin(), a.end());

	for(int i=0; i<n-1; i+=2)
	{
		swap(a[i], a[i+1]);
	}*/

    //ALL EVEN ELEMENTS SHOULD BE GREATER THAN CORRESPONDING ODD ELEMENTS (PREVIOUS AND NEXT)

		for(int i=0; i<n-1; i+=2)
		{
			if(i>0 && a[i-1]>a[i])
				swap(a[i-1], a[i]);

			if(i>0 && a[i]<a[i+1])
				swap(a[i], a[i+1]);
		}

	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";

}