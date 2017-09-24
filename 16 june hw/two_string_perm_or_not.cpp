//check whether two strings are permutation of each other or not
//Exam­ple:

//"sumit" and "tiums" are permutations of each other.

//"abcd" and bdea" are not permutations of each other.
//count of every number is same and every combination is valid

#include<iostream>
#include<string>
#include<map>
using namespace std;

bool checkperm(string s1, string s2)
{
	char count[256]={0};
	if(s1.size()!=s2.size())
		return false;

	for(int i=0; s1[i]!='\0' && s2[i]!='\0'; i++)
	{
		count[s1[i]]++;
		count[s2[i]]--;
	}

	for(int i=0; i<256; i++)
	{
		if(count[i]!=0)
			return false;
	}
	return true;

}
int main()
{
	string s1, s2;
	cin>>s1>>s2;

	cout<<checkperm(s1, s2);
}