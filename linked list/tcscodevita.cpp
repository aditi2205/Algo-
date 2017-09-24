#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int row[]={-1, -1, -1, 0, 1, 1, 1, 0};
int col[]={-1, 0, 1, 1, 1, 0, -1, -1};
int main()
{
	int m, n;
	cin>>m>>n;

	int x, y;
	cin>>x>>y;
	x= x-1;
	y= y-1;
	char mat[m][n];
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cin>>mat[i][j];
	}

	
	queue<pair<int, int> > q;
	bool visited[m][n]={};
	q.push(make_pair(x,y));
	q.push(make_pair(-1,-1));
	visited[x][y]= true;
	int timer=1;
	while(!q.empty())
	{	bool flag= false;
		
		pair<int, int> temp= q.front();
		q.pop();
		int x1= temp.first;
		int y1= temp.second;
		if(x1==-1 && y1==-1)
		{
			
			
			if(q.size()>=1)
			{
				timer++;
				q.push(make_pair(-1,-1));
			}

			continue;
		}
		
	
		for(int i=0; i<8; i++)
		{
			int currow= x1+row[i];
			int curcol= y1+col[i];
			if(currow<m && curcol<n && currow>=0 && curcol>=0 && !visited[currow][curcol] && mat[currow][curcol]=='T')
				{
				
					visited[currow][curcol]= true;
					q.push(make_pair(currow, curcol));
					flag = true;
				}

		}
	
	}
	cout<<timer;


}