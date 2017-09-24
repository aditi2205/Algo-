#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> ans,ans2, ans3;
vector<vector<int> > ans4;
set<int> s;
template<typename T>
void printcontainer(T be, T en)
{
	while(be< en)
	{
		cout<<*be<<" ";
		be++;
	}
}
void printvector(vector<vector<int> > res)
{
	for(int i=0; i<res.size(); i++)
	{
		for(int j=0; j<res[i].size(); j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
class Graph
{
	int v;
	int e;
	vector<int>* adj;

public:
	Graph(int n)
	{
		v= n;
		e=0;
		adj= new vector<int>[n+1];
	}

	void addedge(int a, int b, int directional= false)
	{
		adj[a].push_back(b);
		e++;
		if(directional==true) return;
		adj[b].push_back(a);
		e++;

	}

	void dfs_helper(int src, bool visited[])
	{
		visited[src]= true;
		ans.push_back(src);

		for(int i=0; i< adj[src].size(); i++)
		{
			int adjacent= adj[src][i];
			if(visited[adjacent]==false)
				dfs_helper(adjacent, visited);
		}

		
	}
	void dfs(int src)
	{
		bool *visited= new bool[v+1]();
		
			dfs_helper(src, visited);

	}

	void bfs(int src)
	{
		bool *visited= new bool[v+1]();
		queue<int> q;
		q.push(src);
		while(!q.empty())
		{
			int cur= q.front();
			q.pop();
		     visited[cur]= true;
		     ans2.push_back(cur);

		     for(int i=0; i<adj[cur].size(); i++)
		     {
		     	int neighbor= adj[cur][i];
		     	if(visited[neighbor]==false)
		     	{visited[neighbor] = true;

		     		q.push(neighbor);
		     	}	
		     }
	 }
	

	}
   void connectedutil(int src, bool visited[], vector<int>& sol)
    {
        visited[src]= true;
        sol.push_back(src);
        for(int i=0; i<adj[src].size(); i++)
        {
        	int neighbor= adj[src][i];
        	if(visited[neighbor]==false)
        	{
        		connectedutil(neighbor, visited, sol);
        	}
        }
    }
	vector<vector<int> > connected_components(int src)
	{		
		bool *visited= new bool[v+1]();
		vector<vector<int> > res;
		for(int i=src; i<=v; i++)
		{
			if(visited[i]==false)
			{
				vector<int> sol;
		       connectedutil(i, visited, sol);
		       //printcontainer(sol.begin(), sol.end());
		       res.push_back(sol);
		       //ans4.push_back(ans5);
		}
	}
	return res;
	}

	void shortestpath(int src, int des)
	{
		int *dist= new int[v+1]();
		int *parent= new int[v+1](); //crawling parent

		queue<int> q;
		dist[src]=0;
		parent[src]=src;

		q.push(src);
		while(!q.empty())
		{
			int cur= q.front();
			q.pop();
			for(int i=0; i<adj[cur].size(); i++)
			{
				int neighbors= adj[cur][i];
				if(dist[neighbors]==0 && neighbors!=src)
				{
					q.push(neighbors);
					dist[neighbors]= dist[cur]+1;
					parent[neighbors]= cur;
				}
			}
		}
		cout<<"Shortest distance length:\t"<< dist[des]<<"\n";
		int j= des;
		ans3.push_back(des);
		while(j!=src)
		{
			ans3.push_back(parent[j]);
			j= parent[j];
		}
        printcontainer(ans3.begin(), ans3.end());

	}
int findcycle(int src, bool* visited, int parent)
	{
		visited[src]= true;

		for(int i= 0; i<adj[src].size(); i++)
		{
			int neighbor= adj[src][i];
			if(visited[neighbor]==false)
			{
				if(findcycle(neighbor, visited, src))
				return 1;  //cycle exist
			}
			else if(  neighbor != parent)
			{
				return 1;   //cycle exist
			}
			

		}
		return 0;
	}
	void detectcycle(int src)
	{
		bool *visited= new bool[v+1]();
		int flag=0;
		for(int i=src; i<=v; i++)

		 {
		 	if(visited[i]==false)
		 	{
		     if(findcycle(i, visited, -1))
		 	  flag=1;
		 		
		 	  }
		 }	
		 	  		if(flag)
		 	  			cout<<"YESSSSSSS";
		 	  		else
		 	  			cout<<"NOOOO";


	}
};

int main()
{
	/*Graph g(7);
	g.addedge(1,3);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(3,4);
	g.addedge(2,5);
	g.addedge(5,6);
	g.addedge(6,7);
	g.addedge(7,5);
*/
	Graph g(10);
   g.addedge(1,2);
   g.addedge(1,3);
   g.addedge(2,5);
   g.addedge(3,4);
   g.addedge(5,7);
   g.addedge(6,7);
   g.addedge(8,9);
   g.addedge(4,5);

   
	g.dfs(1);
	g.bfs(1);
	printcontainer(ans.begin(), ans.end());
	cout<<endl;
	printcontainer(ans2.begin(), ans2.end());
	cout<<endl;
	g.shortestpath(4,6);
	cout<<endl;
	cout<<"connected components: \n";
	ans4 = g.connected_components(1);
	printvector(ans4);
	cout<<endl;
	cout<<"Detect cycle in graph\n";
	g.detectcycle(1);
}