#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
void printcontainer(T be, T en)
{
	while(be!=en)
	{
		cout<< *be<<" ";
		be++;
	}
	cout<<"\n";
}
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

	int shortest_distance(int src, int des)
	{
		int *dist= new int[nV+1]();
		bool *visited= new bool[nV+1]();
		int *parent= new int[nV+1];
		queue<int> q;
		dist[src]=0;
		parent[src]= src;
		visited[src]= true;
		q.push(src);
		while(!q.empty())
		{
			int cur= q.front();
			q.pop();
			for(int i=0; i<adj[cur].size(); i++)
			{
				int neighbour= adj[cur][i];
				if(visited[neighbour]==false)
				{
					parent[neighbour]= cur;
					visited[neighbour]= true;
					q.push(neighbour);
					//cout<<cur<<" "<<neighbour<<"\n";
					//cout<< neighbour<<" ";
				    dist[neighbour]= dist[cur]+1;
			}
			}
		}
		vector<int> ans;
		ans.push_back(des);
		int i=des;
		while(src!=i)
		{
			ans.push_back(parent[i]);
			i= parent[i];
		}

		printcontainer(ans.begin(), ans.end());
		return dist[des];
	}

	vector<int> topologicalsort()
	{
		int *indegree= new int[nV+1]();
		for(int v=1; v<=nV; v++)
		{
			for(int i=0; i<ad[v].size(); i++)
			{
				int neighbour= adj[v][i];
				++indegree[neighbour];
			}
		}

		queue<int> q;
		for(int i=1; i<=nV; i++)
		{
			if(indegree[i]==0)
				q.push(i);
		}

		std::vector<int> ans;
		while(!q.empty())
		{
			int cur= q.front();
			q.pop();
			ans.push_back(cur);

			for(int i=0; i< adj[cur].size(); i++)
			{
				int neighbour= adj[cur][i];
				--indegree[neighbour];
				if(indegree[i]==0)
					q.push(i);
			}
		}
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

   //g.bfs(1);

   int d= g.shortest_distance(1,7);

}