#include<iostream>
using namespace std;
const int N=4;
int path[N][N];

void print(int board[][N])
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<path[i][j]<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
}
void reset(int board[][N])
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			path[i][j]=0;
		}
		//cout<<endl;
	}
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

void ratmaze(int board[][N], int x, int y){
	/*
	PRINTING SINGLE SOLUTIONS
	if(x==(N-1)&& y==(N-1))
	{
		path[x][y]=1;
		return true;
	}

	path[x][y]=1;
       			
      if(issafe(board, x, y))
      {
      		if(ratmaze(board,x,y+1)==true)
      			return true;

      		if(ratmaze(board, x+1, y)==true)
      			return true;
      }

      path[x][y]=0;
      return false;*/
	
	//PRINTING ALL SOLUTIONS
	if(x==(N-1)&& y==(N-1))
	{
		path[x][y]=1;
		print(board);
		//reset(board);
		
	    
	}

	path[x][y]=1;
       			
      if(issafe(board, x, y))
      {
      		ratmaze(board,x,y+1);
      		ratmaze(board, x+1, y);
      		path[x][y]=0;			
      }
       else
      {path[x][y]=0;
      	//reset(board);
      }
     
       		
       	
}
int main()
{
	int board[][N]={
		{0,0,0,0},
		{-1,0,-1,0}, 
		{-1,0,0,0},
	    {-1,-1,0,0}
	};

	ratmaze(board,0,0);
	//else
	//	cout<<"No solution exists";

return 0;
}