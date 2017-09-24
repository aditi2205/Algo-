//count the number of set bits in a  number

#include<iostream>
using namespace std;

int setbits(int n)
{
	int count=1;
	int sum=0;
	while(count<=n)
	{
       int np= (n&count);
       if(np!=0)
       	sum= sum+1;
       count=count<<1;
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	cout<<setbits(n);
}