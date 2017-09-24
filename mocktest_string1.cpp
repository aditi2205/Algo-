#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void uncommon_characters(string s1, string s2, int* hash)
{
	for(int i=0; i<s1.size(); i++)
	{
		hash[s1[i]-'a']++;
	}
	for(int i=0; i<26; i++)
	{
		if(hash[i]>0)
			cout<< char('a'+i)<<" ";
	}
	for(int i=0, j=0; i<26, j<s2.size(); i++, j++)
	{
		if(hash[s2[j]-'a']>=1)
		{
			hash[s2[j]-'a']--;
			//cout<< s2[j]<<"count decremented";
		}
		else if(hash[s2[j]-'a']==0)
		{
			cout<< "\n"<< s2[j]<<"\n";
		}
	}

	for(int i=0; i<26; i++)
	{
		if(hash[i]>0)
			cout<< char('a'+i)<<"\n";
	}

}

void encode_string(string s)
{
	int i=0;
	while(i<s.size())
	{
		
	}
}
int main()
{
	string a,b;
	cin>>a>>b;
    int *hashi= new int[26]();
	uncommon_characters(a, b, hashi);
}