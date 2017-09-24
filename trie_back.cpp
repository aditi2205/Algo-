#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 26

class trienode
{
public:
	bool end_of_word;
	trienode* children[MAX];

	trienode()
	{
		end_of_word= false;
		for(int i=0; i<MAX; i++)
			children[i]= NULL;
	}

};

class trie
{
public:
	trienode* root;

	trie()
	{
		root= new trienode();
	}

	void insert(string s)
	{
		trienode* p= root;
		int len= s.size();
		for(int i=0; i<len; i++)
		{
			int idx= s[i]-'a';
			if(p->children[idx]==NULL)
			{
				p->children[idx]= new trienode();
			}
			p= p->children[idx];
		}
		p->end_of_word= true;
	}

	bool search(string key)
	{
		trienode* p= root;
		for(int i=0; i<key.size(); i++)
		{
			int idx= key[i]-'a';
			if(p->children[idx]==NULL)
			{
				return false;
			}
			else
				p= p->children[idx];
		}
		return p->end_of_word;
	}

	bool prefixcheck(string prefix)
	{
		trienode* p= root;
		for(int i=0; i<prefix.size(); i++)
		{
			int idx= prefix[i]-'a';
			if(p->children[idx]==NULL)
				return false;
			else
				p= p->children[idx];
		}
		return true;
	}

};

int main()
{
	trie t;
	string s1= "abc";
	string s2= "abgl";
	string s3= "cdf";
	t.insert(s1);
	t.insert(s2);
	t.insert(s3);

	if(t.search(s1)==true)
		cout<<"S1 found";
	else
		cout<<"S1 not found";
	if(t.search(s2)==true)
		cout<<"S2 found";
	else
		cout<<"S2 not found";
	if(t.search(s3)==true)
		cout<<"S3 found";
	else
		cout<<"S3 not found";
	
	if(t.prefixcheck("abf")==true)
		cout<<"abf prefix matched";
	else
		cout<<"abf not matched";
}