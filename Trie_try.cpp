#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class trie{

public:
	class trienode
	{  public:
		map<char, trienode* > children;
		bool end_of_word;
		public:
		trienode()
		{
			children= new map<char, trienode*>();

			end_of_word= false;
		}
	};

	trienode root;


	trie()
	{
		root= new trienode();
	}




	void insert(string word)
	{
		trienode current= root;
		for(int i=0; i<word.size(); i++)
		{
			char ch= word[i];
			trienode node= current.children[ch];
			if(node==NULL)
			{
				node= new trienode();
				current.children.insert(make_pair(ch,node));

			}
			current= node;
		}
		current.end_of_word= true;

	}

	void search(string word)
	{
		trienode current= root;
		for(int i=0; i<word.size(); i++)
		{
			char ch= word[i];
			trienode node= current.children[ch];
			if(node==NULL)
			{
				return false;
			}
			current= node;
		}
		return current.end_of_word;
	}
};

int main()
{
	string a= "hacker";
	string b= "hackerrank";

	trie t;
	t.insert(a);
	t.insert(b);

	cout<< t.search(a);
}