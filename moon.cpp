#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{

public:
int nV;

list<int>* adj;

public:
	graph(int n)
	{
		nV=n;
		
		adj= new list<int>[nV];
	}
	~graph()
	{
		delete []adj;
	}
	void addedge(int x, int y)//for undirectional graph
	{
		adj[x].push_back(y);
		
	 //If graph is directional then just return
		adj[y].push_back(x);
		
	}
	void dfs(int src, bool visited[], int &cnt)
	{
		visited[src]= true;
		++cnt;
		list<int>::iterator it;
		for(it = adj[src].begin(); it!=adj[src].end(); it++)
		{
			if(visited[*it]==false)
				dfs(*it, visited, cnt);
		}
	}

};

long long int findnum(int arr[],int sze, int n)
{
	int totalcomb= n(n-1)/2;

	for(int i=0; i<szel; i++)
	{
		totalcomb-= arr[i]*(arr[i]-1)/2;
	}
}

int main()
{
   int x,y;
   int n;
   int p;
   cin>>n>>p;
   graph g(n);

   for(int i=0; i<p; i++)
   {
   	cin>>x>>y;
   	g.addedge(x,y);
   }
  int numberofcc;
  int cntofcc[(int)10e5]={};

  bool *visited= new bool[n]();

  for(int i=0; i<n; i++)
  {
  	if(visited[i]==false)
  	g.dfs(i, visited, cntofcc[numberofcc]);
  	++numberofcc;
  }



}