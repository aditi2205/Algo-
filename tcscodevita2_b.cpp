#include<iostream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define c 4.186666666666666666666666666667
int main()
{
	int n;
	cin>>n;
	float a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	float k;
	cin>>k;
	float per= (float)k/100;
	//ṭcout<<per;
	float ele= 1.0000000000;
	float sum=0;
	sort(a, a+n);
	for(int i=0; i<n; i++)
	{
		cout.precision(10);
		float a1= a[i];
		float p= (float)c*((float)pow(a1,3));
		
		float val1= (float)pow((float)(ele-per), (n-i-1));
		
		float final= (float)(p*val1);
		cout<<final<<"\n";
		sum= (float)sum+final;

	}
	printf("%.2f\n", (sum*100.0)/100.0);
//cout << std::setprecision(3) << std::fixed << sum;
}