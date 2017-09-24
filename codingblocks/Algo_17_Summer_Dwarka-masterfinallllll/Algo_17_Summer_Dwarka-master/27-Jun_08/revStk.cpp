//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void insertAtBottom(stack<int>& s, int x){
	if (s.empty()){
		s.push(x);
		return;
	}
	int cur = s.top();
	s.pop();
	insertAtBottom(s, x);
	s.push(cur);
}


void reverseStk(stack<int>& s){
	if (s.empty() == true){
		//nothing to do 
		return;
	}

	int cur = s.top();
	s.pop();
	reverseStk(s);	//stack of 1 element less than "N" will be reversed
	//HOW??? Recursion is the ans, Man!
	insertAtBottom(s, cur);
}

void reverseque(queue<int>& q)
{
	if(q.empty())
	{
		return;
	}
	int cur= q.front();
	q.pop();
	reverseque(q);
	q.push(cur);
}

int main(){
	stack<int> s;
	for(int i = 0; i < 5; ++i){
		int x; cin >> x;
		s.push(x);
	}

	reverseStk(s);

	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();

	}
	queue<int>q;
	for(int i=0; i<5; i++)
	{
		int x;
		cin>>x;
		q.push(x);
	}
	reverseque(q);
	while(!q.empty())
	{
		cout<<"\n"<<q.front();
		q.pop();
	}

}