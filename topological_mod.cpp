#include <vector>
#include <iostream>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
void printContainer(T be, T en) {
	//be and en are pointers-like(iterators) object
	while (be != en) {
		cout << *be << " ";
		++be;
	}
	cout << endl;
}


class Graph {
	typedef vector<string> vi;		//vi is another name for type vector<int>
	int nV;
	int nE;
	map<string, vector<string> >adjList;
public:

	Graph(int n) {
		nV = n;
		
		//adjList = new vi[nV + 1];		//dynamic memeory allocation
		//To "address" n vertices I need nV + 1 space--index adjusting
	}

	

	void addEdge(string x, string y) {
		if(adjList.find(x)!=adjList.end())
		{vector<string> temp=adjList[x];
		temp.push_back(y);
	    }
	    else
	    {
	    	vector<string> temp;
	    	temp.push_back(y);
	    	adjList.insert(make_pair(x, temp));
	    }
		
	}

	
	vector<string> topologicalSort() {
		//calculate inDegree
		

		map<string, int>inDegree;
		map<string, vector<string> >::iterator it;
		for(it= adjList.begin(); it!=adjList.end(); it++)
		{
			string s= it->first;
			vector<string> v= it->second;
			sort(v.begin(), v.end());
			for(int i=0; i<v.size(); i++)
			{
				if(inDegree.find(v[i])==inDegree.end())
				{
					inDegree.insert(make_pair(v[i],1));
				}
				else
					inDegree[v[i]]++;
			}
		}

		queue<string> q;
		map<string, int>::iterator it1;
		//search for potential candidates
		for(it1= inDegree.begin(); it1!=inDegree.end(); it1++)
		{
			if(it1->second==0)
				q.push(it->first);
		}
		
		
		vector<string> ans;

		while(!q.empty())
		{
			string curr= q.front();
			q.pop();
			cout<<curr<<"\n";
			ans.push_back(curr);

			vector<string> temp= adjList[curr];
			for(int i=0; i<temp.size(); i++)
			{
				string neighbor= temp[i];
				--inDegree[neighbor];
				if(inDegree[neighbor]==0)
					q.push(neighbor);
			}
		}
		
		return ans;
	}
};

int main(){
	//Lets go Mauritius
	//P T I V E G
	//6 4 3 5 1 2

int n;
cin>>n;
	Graph G(n);
	int m;
	cin>>m;
	for(int i=0; i<m; i++)
	{
		string a, b;
		cin>>a>>b;
		G.addEdge(b,a);
	}

	

	vector<string> topo_res = G.topologicalSort();
	//printContainer(topo_res.begin(), topo_res.end());
}