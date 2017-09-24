#include<iostream>
using namespace std;

const int global=8;

int mat[global][global];
//dir false  go down
//dir true go up
void generate(int val, int i, int j, int size, bool dir)
{
	if(i>=size || j>=size)
		return;
	if(val==(size*size))
		return;
	
	mat[i][j]= val++;
	mat[i][j+1]= val++;
	mat[i+1][j]= val++;
	mat[i+1][j+1]= val++;
	/*if((size-1)-(j+1)>=2)
	generate(val, i, j+2, size);
	else
	generate(val, i+2, 0, size);*/
	if((j+1)%4==0)
	{	
		if(dir==false)
		generate(val, i+2, 0, size, !dir);
		else
		generate(val, i-2, j+1, size, !dir);
	}
	else
		generate(val, i, j+2, size, dir);

}
int main()
{
	/*int n;
	cin>>n;
	int size= (1<<n);*/
	
	
	for(int i=0; i<global; i++)
	{
		for(int j=0; j<global; j++)
			mat[i][j]=0;
	}
	generate(1,0,0,8, false);
	for(int i=0; i<global; i++)
	{
		for(int j=0; j<global; j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}

}