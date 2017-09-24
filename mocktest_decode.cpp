#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;


void printsubstring(string str)
{
	stack<char> s;
	string temp1="", temp2="";
	for(int i=str.size()-1; i>=0; i--)
	{
		temp1= "";
		if(isdigit(str[i]))
		{
			int repeat= int(str[i]-'0');
			//cout<<"repeat=="<<repeat<<"\n";
			while(!s.empty())
			{
				temp1= temp1+ s.top();
				//cout<<"\ns.top is "<<s.top()<<"\n";
				s.pop();
			}
			temp1= temp1+ temp2;
			//cout<<"temp 1 is"<<temp1<<"\n";
			string intermediate= temp1;
			for(int j=0; j< repeat-1; j++)
			{
				temp1+= intermediate;
				
			}

			temp2 = temp1;

		}

		else
		{
			if(str[i]=='[' || str[i]==']')
				continue;
			else
				{s.push(str[i]);
					//cout<<"\n character pushed is\n"<<str[i]<<"\n";
		}
	}


}
cout<<temp1<<"\n";
}

int main()
{
	string str;
	cin>>str;

	printsubstring(str);

}