#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class vertex{
public:
	int id;
	int wt;
	vertex(int i, int w)
	{
		id=i;
		wt=w;
	}

	bool operator<(const vertex &v)const
	{
		return wt<v.wt;
	}
};


	
class graph{
	list<vertex>* adjlist;
	int nv;
	int ne;
public:
	
	graph(int n)
	{
		int nv= n;
		adjlist= new list<vertex>[nv+1]();
		ne=0;
	}


	void addedge(int x, int y, int wt)
	{
		adjlist[x].push_back(vertex(y,wt));
		++ne;
		adjlist[y].push_back(vertex(x,wt));
		++ne;
	}

	int diksha(int src, int dest)
	{
		int *dist= new int[nv+1];
		vertex a(src,0);
		//Initially all are set to infinity
		const int inf= (int)1e7;

		for(int i=1; i<=nv; i++)
		{
			dist[i]= inf;
		}
		priority_queue<vertex> q;
		q.push(a);

		while(!q.empty())
		{
			vertex curver= q.top();
			q.pop();
			dist[curver.id]= min(curver.wt, dist[curver.id]);

			for(list<vertex>::iterator it= adjlist[curver.id].begin(); it!= adjlist[curver.id].end(); ++it)
			{
				vertex neighbor= *it;
				int distfromsrc= neighbor.wt+ curver.wt;
				if(distfromsrc<dist[neighbor.id])
				q.push(vertex(neighbor.id, distfromsrc));
			}
		}
		return dist[dest];
	}
};
int main()
{
   graph g(7);
   g.addedge(1,2,10);
   g.addedge(1,3,80);
   g.addedge(2,5, 20);
   g.addedge(5,7, 10);
   g.addedge(5,6,50);
   g.addedge(7,6,5);
   g.addedge(3,4,70);

   int d= g.diksha(1,7);
   cout<<d;

}