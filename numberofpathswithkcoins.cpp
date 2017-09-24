#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=3;
int path[N][N];
int maxcount= INT_MIN;
string ans;
void print(int board[][N])
{ string sol;
	for(int i=0; i<N; i++)
	{
		sol.clear();
		int c=0;
		for(int j=0; j<N; j++)
		{
			//cout<<path[i][j]<" ";
			if(path[i][j]==1)
				{//cout<<board[i][j]<<"-->";

			      char *a= itoa(board[i][j]);
			      string b= string(a);
			      sol= sol+b;
			      cout<<sol<<" ";
			     c++;
			 }
			 if(c>maxcount)
			 {
                ans= sol;
			 }

		}
		
	}
	cout<<endl;
	
}

bool issafe(int board[][N], int x, int y)
{
    //movement should be within dimensions
    //the movement should not lead to an obstacle
    if(x<0 || y<0 || x>=N || y>=N)
    	return false;
    if(board[x][y]==-1)
    	return false;
    return true;
}

void ratmaze(int board[][N], int x, int y, int count, int k){

	if(x==(N-1) && y==(N-1) && count==(k-1))
	{
		path[x][y]=1;
		print(board);
	}

	path[x][y]=1;
	count+=board[x][y];

	if(issafe(board,x,y))
	{
		ratmaze(board, x+1, y, count, k);
		ratmaze(board, x, y+1, count, k);

		path[x][y]=0;
		count= count-board[x][y];
	}
	else
		path[x][y]=0;
	
     
       		
       	
}
int main()
{
	int board[][N]={
		{1,2,3},
		{4,6,5}, 
		{3,2,1},
	    
	};
  int k=12;
	ratmaze(board,0,0,0,k);


return 0;
}