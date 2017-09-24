#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class compare{
  public:
	bool operator()(const int &x, const int &y)const{
		return x>y;
	}
};
priority_queue<int> maxheap;
priority_queue<int, vector<int>, compare > minheap;
void push(int ele)
{
	
	if(maxheap.empty())
	{
		maxheap.push(ele);
		return;
	}

    minheap.push(ele);
    int s1= maxheap.size();
    int s2= minheap.size();

   // cout<<"\n"<<s1<<" "<<s2<<"\n";

    if(s1<s2)
    {
    	int element= minheap.top();
    	//cout<<"\n element is\n"<<element;
    	maxheap.push(element);
    	minheap.pop();
    }
 /* cout<<"\nminheap top: "<<minheap.top();
  cout<<"\n maxheap top: "<<maxheap.top()<<"\n";
cout<<"\n--------------------------------\n";
*/}
void top()
{
	//print the median till now and then delete the median from the heap and then balance the tree also
	if(!maxheap.empty())
	{
		cout<<maxheap.top()<<"\n";
		maxheap.pop();
	}
	if(minheap.size()>maxheap.size())
			{
				int data= minheap.top();
				minheap.pop();
				maxheap.push(data);
			}

}
int main()
{
	

int t;
cin>>t;
while(t--)
{
	int c;
	while (maxheap.empty() == false)
    {
        maxheap.pop();
    }
    while (minheap.empty() == false)
    {
        minheap.pop();
    }
 
	while(1)
	{
		cin>>c;
		if(c!=0 && c!=-1)
		{
			push(c);
		}
		else if(c==-1)
		{
			top();
		}
		else if(c==0)
			{  
				break;
			}
	}
	cout<<"\n";
}
}