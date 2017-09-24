#include <iostream>
#include<bits/stdc++.h>
#include <numeric>
using namespace std;
int count1=0;
int maxi= INT_MIN;
bool flag= true;
void  check(int  n, int ts, int tf, int curtime, int res, int i, int mat[][3])
{
	if(curtime>tf)
		return ;
	if(curtime+ mat[i][2] > tf)
	{
		flag= false;
		return;
	}
	if(i>n-1) return;
	
	if(maxi< res)
		maxi= res;
	//cout<<count1++<<" "<<res<<" "<<maxi<<"\n";
	if(curtime+ts<= mat[i][0])  //start time
	{
		curtime= mat[i][0]+mat[i][2]; //start time of bus plus travelling duration
		check(n, ts, tf, curtime, res+1, i+1, mat);
	}
	else if(curtime+ts>mat[i][0])
	{
		//either do sightseeing or don't do sightseeing
		//if we don't want to do sightseeing then we have board the coming train and that will be coming at taht si+fi which is just greater thancurtime
		int comingtime= curtime+ts;
		int coming1= mat[i][0];
		while(coming1<= comingtime)
			coming1= coming1+mat[i][1];
		comingtime= coming1+ mat[i][2];
		check(n,ts, tf, comingtime,res+1, i+1, mat ); 


		int coming= mat[i][0];
		while(coming<= curtime)
			coming= coming+mat[i][1];
		curtime= coming+ mat[i][2];
		check(n,ts, tf, curtime,res, i+1, mat ); //no sight seeing


	}
}
int main()
{
	int t;
	cin>>t;
	int i=1;
	while(i<=t)
	{
		count1=0;
		maxi= INT_MIN;
	    flag= true;
	int n, ts, tf;
	cin>>n>>ts>>tf;

	int mat[n-1][3];
	for(int i=0; i<n-1; i++)
	{
		
			int s, f, d;
			cin>>s>>f>>d;
			mat[i][0]=s;
			mat[i][1]=f;
			mat[i][2]=d;
	}
	int curtime= 0;
	int res=0;
	int i=0;
	check(n, ts, tf, curtime, res, i, mat);
	if(flag)
	
		cout<<"Case #"<<i<<": "<<maxi;
	else
		cout<<"Case #"<<i<<": "<<"IMPOSSIBLE";
	i++;
}

}