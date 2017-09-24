#include<iostream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
bool p1(string s)
{
	bool flag= false;
	if(s[0]<s[1])
		flag= true;
	bool flag2a= false, flag2b=false;
   for(int i=1; i<s.size()-1; i++)
   {
   	  if(flag==false)
   	  {
   	  	if(flag2a==false && s[i]>=s[i+1] || (flag2a==true && s[i]<=s[i+1]))
   	  	{
   	  		return false;
   	  	}
   	  }
   	  if(flag==true)
   	  {
   	  	if(flag2a==false && s[i]<=s[i+1] || (flag2a==true && s[i]>=s[i+1]))
   	  	{
   	  		return false;
   	  	}
   	  }
   	  flag2a= !flag2a;
   }
   return true;
}

bool p2(string s)
{
	int a= s[0]-'0';
	int b= s[s.size()-1]-'0' ;
	//cout<<a<<" "<<b<<"\n";
	return (a%2==0)||(b%2==0);
}

bool p3(string s)
{
	int top=0, trough=0;
	for(int i=0; i<s.size()-1; i++)
	{
		if(s[i+1]>s[i]) top++;
		else if(s[i+1]<s[i]) trough++;


	}
	if(top>=2 && trough>=2) return true;
	return false;
}
bool checkjagged(int n)
{
	string temp;
    while(n>1)
    {
    	temp.push_back((n%10)+'0');
    	n= n/10;
    }
    reverse(temp.begin(), temp.end());
   
    return ((p1(temp))&& (p2(temp) || p3(temp)));
}
int main()
{
	int n;
	cin>>n;
	for(int i=n; i>99; i--)
	{
		if(checkjagged(i))
		{
			cout<<i;
			break;
		}
	}
}
/*
Owing to the destructive misery caused by Hurricane Sheridan, a little boy named Woody and his parents are now re-sheltering themselves to a new place popularly known as The Rocks. The place gets its name set by the scintillating view the mountainous region has to offer.

Woody thought of the jagged terrain on which his house stands and came up with an innovative idea. He thought of numbers that could represent a Jagged terrain and came up with the idea of a Jagged Number.

Property 1: A Jagged Number is one where every subsequent digit rises and falls (in value) alternatively throughout. However, like most terrains aren't complete with at least 1 smooth surface or perhaps 2; so does a Jagged number. A Jagged number is given the characteristic of a smooth Edge, a smooth Top and a smooth Trough. Woody decided to let all the even digits (0, 2, 4, 6, 8, 0) represent smooth surfaces.

Property 2: A Jagged number has at least 1 smooth edge. That is, either the first digit or the last digit or both digits in a Jagged number must be even.

Property 3: A Jagged number has a combination of at least 2 Tops and Troughs. Top refers to the jump to the higher number while a Trough refers to the slump to a lower number.

An Edge is neither counted as a Top nor a Trough. So the higher/lower number at the start/end can't be regarded as a Top/Trough but simply an Edge.

Also, Property 1 is mandatory, while just one of Property 2 and 3 is mandatory.

A Jagged number, however can have all 3 Properties.

For example, the number 163723 is a Jagged number as

- it starts at 1 
- rises to 6(smooth Top) 
- drops to 3 
- rises to 7 
- drops to 2(smooth Trough) 
- and finally rises back to 3

The numbers 4165, 8231, 152 are all Jagged Numbers.

However, numbers like 4567, 14375, 3112, 154713 are not Jagged Numbers.

To help him sleep at night, he decided he'll count himself to sleep. However, every number that he counts, he wishes to see if it is jagged or not, just like the place he lives in.

So every night, Woody starts counting from 100, 101, 102... and checks every number for its Jagged nature until he falls asleep. You need to find out the last Jagged number he called off before going to sleep.
Input Format:

Last number Woody counted before falling sleep
Output Format:

Last Jagged Number Woody counted
Constraints:

N ≤ 105

Example 1

Input 
3456

Output 
3438

Explanation 
It can be seen none of 3439, 3440,…., 3456 are Jagged numbers.

Example 2

Input 
2615

Output 
2615

Explanation 
2615 is a Jagged number.*/