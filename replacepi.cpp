#include<iostream>
#include<string>
using namespace std;
void replacepi(string &s, int i)
{
	if(i>s.size())
	return ;
    if(i>=0 && i<s.size()-2)
    {
          if(i-1>0 && s[i-1]==' ' && s[i]=='p' && s[i+1]=='i' && s[i+2]==' ')
          	s.replace(i, 2, "3.14");

          replacepi(s,i+1);
    }
    if(i>=0 && i<s.size()-1)
    {
    	if(s[i-1]==' ' && s[i]=='p' && s[i]=='i')
    		s.replace(i,2,"3.14");
    }
   /* if(n<0)
    	return "";
   replacepi(s,n-1);
	if(s[n]=='p' && s[n+1]=='i')
		return s.replace(n,2,"3.14");
	else
		return s;
*/
}
int main()
{
	string s;
	getline(cin,s);
	string s1= "3.14";
	/*for(int i=0; i<s.size()-1; i++)
	{
		if(s[i]=='p' && s[i+1]=='i')
		{

			s.replace(i,2,s1);
				}
		
	}*/
	replacepi(s, 0);
	cout<<s;
	//cout<<s;
}