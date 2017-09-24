#include<iostream>
using namespace std;
class myvector{
 int *p;
public:
	myvector()
	{
		p= new int;
	}
	myvector(int n)
	{
       //allocate a size n to the vector
		p= new int[n+1];
	}
	int size()
	{
		//returns curently allocated size
		int i=0;
		int c=0;
		for(; p[i]; i++)
			c++;
		return c;
	}
	void push_back(int n)
	{
		//allocate space for this node
		//save previous data and then allocate new memory
		int i=0;
		for(; p[i]; i++);
		p= new int[2];
	    p[i+1]=n;	
	}
	void pop_back()
	{
		//deallocate last allocated node
		int i=0;
		for(; p[i]; i++);
			delete(p);

	}
};
int main()
{
	myvector v(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	
}