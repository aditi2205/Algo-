#include<iostream>
#include<conio.h>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int t1;
	cin>>t1;
	for(int t=0; t<t1; t++)
	{
		double x, y, z, x2, y2, z2, x3, y3, z3;


		cin>>x>>y>>z;
		cin>>x2>>y2>>z2;
		cin>>x3>>y3>>z3;
		double mini= min(x, min(x2,x3));
		double maxi= max(x, max(x2, x3));

		double dis= abs(mini-maxi);

		double ans= (double)(dis/6);
		cout<<"Case #"<<t+1<<": "<<std::fixed<<setprecision(10)<<ans<<"\n";
		
	}
}