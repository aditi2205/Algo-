#include<iostream>
using namespace std;

void printsub(char s[], int be, char res[], int ridx)
{
     if(s[be]=='\0')
     {
     	res[ridx]='\0';
     	cout<<res<<"\n";
     	return;
     }

     
     res[ridx]= s[be];
     printsub(s, be+1, res, ridx+1);
     printsub(s, be+1, res, ridx);
}
void substring(int start, int end, int n)
{
	if(start==n && end==n)
		return ;
	else
	{
		if(end==n+1)
			substring(start+1, start+1);
		else
		{
			
		}
	}
}
int main()
{
	char s[20];
	char res[20];
	cin>>s;
	printsub(s,0,res,0);
}