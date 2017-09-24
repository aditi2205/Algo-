#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool doesKnow(int x, int y){
	static int mat[][4] = {
		{0, 0, 1, 1},
		{0, 0, 1, 0},
		{0, 0, 0, 0},
		{1, 1, 1, 1}
	};
	return mat[x][y];
}

int celeb(int n){
	//implement it!
	//STACK APPROACH
	/*stack<int> s;
	int i=0;
	while(i<n)
	{
		s.push(i);//stack contains all the potential celebrities
		
		i++;
	}
	while(s.size()!=1)
	{
		int a= s.top();
		s.pop();
		int b= s.top();
		s.pop();
		if(!doesKnow(a,b))//if a knows b then a cannot be the celebrity so we will push back b
			s.push(a);
		else if(!doesKnow(b,a)) //if b does not know a then a cannot be the celebrity
			s.push(b);
	}
	return s.top();*/
	int i=0, j=n-1;
	cout<<i<<j;
		int counts=n-1;
	while(i<=j)
	{
         cout<<"\n"<<i<<" "<<j<<":";
		if(!doesKnow(i,j))  //i does not know j so j cant be the celebrity
			{cout<<" i does not know j so j cant be the celebrity";
				j--;}
		else if(doesKnow(i,j))//  i know j so i cant be the celebrity
			{cout<<"i know j so i cant be the celebrity";
				i++;}
				}

		

	
	cout<<"\n";
	return i;
}

int main(){
	int N = 4;
	//Four people viz. 0 1 2 3
	cout << celeb(N); // 2 is the celeb
}