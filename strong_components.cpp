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
		delete [] adj;
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
		bool *visited= new bool[nV+1]();
		//initialising all nodes to 0
		//pointer to a bool array
		for(int i=src; i<=nV; i++)	
		{  
			if(visited[i]==false)
			{
				//cout<<"\n"<<i<<":";
			dfs_helper(i, visited);
			cout<<"\n";
		    }
		}
		delete [] visited;
	}


};

int main()
{
   graph g(9);
   g.addedge(1,2);
   g.addedge(1,3);
   g.addedge(2,5);
   g.addedge(3,4);
   g.addedge(5,7);
   g.addedge(6,7);
   g.addedge(5,7);
   g.addedge(8,9);

   g.dfs(1);

}