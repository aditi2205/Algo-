#include<iostream>
using namespace std;
void toh(int n,char s, char d, char a)
{
	if(n==0)      
		return;
	toh(n-1,s,a,d);
	cout<<n<<"th disk from "<<s<<" to "<<d<<"\n";
	
	toh(n-1,a,d,s);
	
}
int main()
{
	int n;
	cin>>n;
	toh(n,'S','D','A');
}