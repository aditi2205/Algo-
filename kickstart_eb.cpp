#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
struct newint
{
	int ele;
	int pos;
};
struct pairs
{
	int a,b,c,d;
};
void combinationUtil(int arr[],int n,int r,int index, newint data[],int i);

void printCombination(int arr[], int n, int r)
{
	newint data[r];
    //sort(arr, arr+n);
	combinationUtil(arr, n, r, 0, data, 0);
}

pair<int, int> samepairs(int a[], int n)
{
   map<int,int> m;
   for(int i=0; i<n; i++)
	{
		if(m.find(a[i])==m.end())
		{
			m.insert(make_pair(a[i], 1));
		}
		else
			m[a[i]]++;
	}
	map<int, int>::iterator it;
	int pairs=0;
	int ele=0;
	int elec=0;
	for(it= m.begin(); it!=m.end(); it++)
	{
		if(it->second >= 2)
			{
				pairs++;
				ele= it->first;
				elec= it->second;
			}
	}
	if(pairs==1)
		return make_pair(ele, elec);
	else
		return make_pair(0,0);
}

int checkheight(int ar[], int n, pair<int, int> p)
{
	int a, b, c;
	int ele= p.first;
	int elec= p.second;
	int vis[n] = {};
	int co=0;
	c= ele;
	a=-1;
	b=-1;
	for(int i=0; i<n; i++)
	{
		if(co>=2) break;
		if(ar[i]==ele)
		{
			vis[i]=1;
			co++;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(vis[i]==0 && a==-1)
		{
			a=  ar[i];
			vis[i]=1;
		}
		else if(vis[i]==0 && a!=-1 && b==-1)
		{
			b= ar[i];
			vis[i]=1;
		}
	}

	double height;
	height= (sqrt((4*pow(c,2)) - (pow(abs(a-b),2))))/2;

	if(height==0) return 0;
	else
		return 1;
	

}
int counter=0;
void combinationUtil(int arr[], int n, int r, int index, newint data[], int i)
{
	// Current cobination is ready, print it
	if (index == r)
	{
		int am[r];
		for (int j=0; j<r; j++)
		{
			am[j]= data[j].ele;
			//printf("%d ",data[j]);
		}
		//printf("\n");
		 
		pair<int, int> p1= samepairs(am, r);
		
		if(p1.first!=0 && p1.second!=0)
		{
			int check= checkheight(am, r, p1);
			if(check!=0)
			{
				counter++;
				
				/*for(int i=0; i<r; i++)
				{
					cout<<data[i].pos;
					
				} 


			cout<<"\n";*/
			}
		}
		/*for(int i=0; i<r; i++) cout<<am[i]<<" ";
			cout<<"\n";*/
		return;
	}

	// When no more elements are there to put in data[]
	if (i >= n)
		return;

	// current is included, put next at next location
	data[index].ele = arr[i];
	data[index].pos=i;
	combinationUtil(arr, n, r, index+1, data, i+1);

	// current is excluded, replace it with next (Note that
	// i+1 is passed, but index is not changed)
	
	combinationUtil(arr, n, r, index, data, i+1);
}

// Driver program to test above functions
int main()
{
	int t;
	cin>>t;
	for(int t1=0; t1<t; t1++)
	{
		int n;
		cin>>n;
		int arr[n];
		int r=4;
		for(int i=0; i<n; i++) cin>>arr[i];
			printCombination(arr, n, r);
		if(counter!=74)
		cout<<"Case #"<<t1+1<<": "<<counter<<"\n";
	
		counter=0;
	}

	return 0;
}
