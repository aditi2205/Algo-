#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{

typedef vector<int> vi;
int nV;
int nE;
vector<int>* adj;

public:
	graph(int n)
	{
		nV=n;
		nE=0;
		adj= new vi[nV+1]; //dynamic memory allocation
	}
	~graph()
	{
		delete []adj;
	}
	void addedge(int x, int y, bool directional= false)//for undirectional graph
	{
		adj[x].push_back(y);
		++nE;
		if(directional) return;  //If graph is directional then just return
		adj[y].push_back(x);
		++nE;
	}
	//traversal can be done in two ways: BFS or DFS
	//DFS
	void dfs_helper(int src, bool *visited)
	{

		visited[src]= true;
		cout<< src<<" ";

		for(int i=0; i<adj[src].size(); i++)
		{
			if(visited[adj[src][i]]==false)
				dfs_helper(adj[src][i], visited);

		}	
	}
	void dfs(int src)
	{
		bool *visited= new bool[nV]();
		//initialising all nodes to 0
		//pointer to a bool array
		dfs_helper(src, visited);

		delete [] visited;
	}

	//BFS

	void bfs(int src)
	{
		bool *visited = new bool[nV+1];
		queue<int> q;
		visited[src]= true;
		q.push(src);

		while(!q.empty())
		{
			int curele= q.front();
			q.pop();
			cout<< curele<<" ";
			for(int i=0; i<adj[curele].size(); i++)
			{
				int neighbour= adj[curele][i];
				if(visited[neighbour]==false)
				{
					visited[neighbour]= true;
					
					q.push(adj[curele][i]);
				}
			}
		}
		delete [] visited;
	}
};

int main()
{
   graph g(7);
   g.addedge(1,2);
   g.addedge(1,3);
   g.addedge(2,5);
   g.addedge(3,4);
   g.addedge(5,7);
   g.addedge(6,7);
   g.addedge(5,7);

   g.bfs(1);

}