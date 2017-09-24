#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int min(int a, int b, int c)
{
	return min(a, min(b,c));
}
int editdistance(string s1, string s2, int be1, int be2)
{

	if(be1==s1.size())
		return s2.size()-be2;

	if(be2==s2.size())
		return s1.size()-be1;

	if(s1[be1]==s2[be2])
	{
		return editdistance(s1, s2, be1+1, be2+1);
	}

	else
	{                                  //insert                     //delete                               //replace
		return 1+min(editdistance(s1, s2, be1, be2+1), editdistance(s1, s2, be1+1, be2), editdistance(s1, s2, be1+1, be2+1));
	}
}
int main()
{
	string s1, s2;
	cin>>s1>>s2;

	cout<< editdistance(s1, s2, 0,0);
}