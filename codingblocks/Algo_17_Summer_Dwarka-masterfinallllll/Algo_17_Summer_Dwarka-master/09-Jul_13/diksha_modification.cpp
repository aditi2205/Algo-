//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <queue>
#include <list>
#include<bits/stdc++.h>
using namespace std;

class Vertex{
public:
	int id;
	int wt;
	Vertex(int i, int w){
		id = i;
		wt = w;
	}

	bool operator<(const Vertex& X) const {
		return wt < X.wt;
	}
};

class comparator{
public:
	bool operator()(Vertex& A, Vertex& B){
		return A.wt < B.wt;
	}
};

class Graph{
	list<Vertex>* adjList;
	int nV;
	int nE;
public:
	Graph(int n){
		nV = n;
		adjList = new list<Vertex>[nV + 1]();
		nE = 0;
	}


	void addEdge(int src, int dest, int wt){
		adjList[src].push_back(Vertex(dest, wt));
		++nE;

		adjList[dest].push_back(Vertex(src, wt));
		++nE;
	}

	int dijikstra(int src){
		int * dist = new int[nV + 1];
		const int inf = INT_MAX;

		//initially all set to inf
		for(int i = 0; i <= nV; ++i){
			dist[i] = inf;
		}

		// priority_queue<Vertex, vector<Vertex> , comparator> q;
		priority_queue<Vertex> q;

		Vertex V(src, 0);

		q.push(V);
		priority_queue<Vertex> q1;
		while(q.empty() == false){
			Vertex curVer = q.top();
			q1.push(curVer);
			q.pop();
			
			dist[curVer.id] = min(curVer.wt, dist[curVer.id]);

			//push all neighbours
			for(list<Vertex>::iterator it = adjList[curVer.id].begin(); it != adjList[curVer.id].end(); ++it){
				Vertex neighbor = *it;
				int distFromSrc = neighbor.wt + curVer.wt;
				if (distFromSrc < dist[neighbor.id]) {
					Vertex X(neighbor.id, distFromSrc);
					q.push(X);
				}
			}
		}
		vector<int> v;
		while(!q1.empty())
		{
			Vertex cur= q1.top();
			v.push_back(cur.id);
			q1.pop();
		}
		reverse(v.begin(), v.end());
		for(int i=0; i<v.size(); i++)
			cout<<v[i]<<" ";
		cout<<endl;
		int sum=0;
		for(int i=1; i<=nV; i++)
			sum+=dist[i];

         cout<<sum;
		
	}

	~Graph(){
		delete [] adjList;
	}
};


int main(){
    int n;
    cin>>n;
    int src;
    cin>>src;
	Graph G(n);
    while(1)
    {
        int v1, v2, wt;
        cin>>v1;
        if(v1==0)
        break;
        
        cin>>v2;
        cin>>wt;
        G.addEdge(v1, v2, wt);
    }


	G.dijikstra(src);
}