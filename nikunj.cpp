#include<iostream>
using namespace std;

class nikunj
{
	int n;
	float b;
	double c;
	//int arr[n];

	public:
		nikunj(){}
		nikunj(int x, int y, int p)
		{
			n=x;
			b=y;
			c=p;
		}

		void print()
		{
			cout<<n<<" "<<b<<" "<<c;

			/*for(int i=0; i<n; i++)
				cout<<arr[i]<<" ";*/
		}

};
int main()
{
	nikunj ab(5,3, 6);
	cout<<sizeof(int);
	cout<<endl;
	cout<<sizeof(float);
	cout<<endl;
	
	cout<< sizeof(ab);
	cout<<endl;
	ab.print();

}