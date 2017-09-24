#include <iostream>
#include<bits/stdc++.h>
#include <numeric>
using namespace std;
int count1=0;
int maxi= INT_MIN;
void  check(int  n, int ts, int tf, int curtime, int res, int i, int mat[][3])
{
	
	if(curtime>tf )
		return ;

	if(i>n-1) return;
	
	if(maxi< res && curtime<tf)
		maxi= res;
	//cout<<count1++<<" "<<curtime<<" "<<res<<" "<<maxi<<"\n";
	if(curtime+ts<= mat[i][0])  //start time
	{
		curtime= mat[i][0]+ mat[i][2]; //start time of bus plus travelling duration
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

int checkpossible(int n, int ts, int tf, int curtime, int i, int mat[][3])
{
	if(curtime> tf)
		return 0;
	if(i>n-1)
		return 0;
	if(curtime<=tf && i==n-1)
		return 1;
	if(curtime<= mat[i][0])
	{
		curtime= mat[i][0]+mat[i][2];
		return checkpossible(n, ts, tf, curtime, i+1, mat);
	}
	else
	{
		int newstart= mat[i][0];
		while(newstart<= curtime)
			newstart+= mat[i][1];
		curtime= newstart+mat[i][2];
		return checkpossible(n, ts, tf, curtime, i+1, mat);
	}
}
int main()
{
	int t;
	cin>>t;
	
	for(int c=1; c<=t; c++)
	{
		count1=0;
		maxi= INT_MIN;
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
		int val= checkpossible(n,ts, tf, curtime, i, mat);
		if(val==0)
			cout<<"Case #"<<c<<": "<<"IMPOSSIBLE"<<"\n";
		else
		{
		check(n, ts, tf, curtime, res, i, mat);

		cout<<"Case #"<<c<<": "<<maxi<<"\n";
	}
	
    }

}