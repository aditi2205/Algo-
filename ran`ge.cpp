#include<bits/stdc++.h>
using namespace std;
class member
{  public:
  int val;
  int row1;
  int col1;

  member(int a, int b, int c)
  {
    val= a;
    row1=b;
    col1=c;
  }


};
class compare{
public:
  bool operator()( const member x, const member y) const
  {
    return x.val>y.val;
  }
};
void findSmallestRange(int a[10][10], int n, int k)
{
      //code here
      //k is number of lists
      //n is the size of each list
      int start, end;
      int maxstart=-1, maxend=-1;
      priority_queue< member , vector<member>, compare > p;
      priority_queue<int> p1;
      for(int i=0; i<k; i++)
      {
              int j=0;
              cout<<"Pushed "<<a[i][0]<<"\n";
              member m(a[i][0], i, j);
              p.push(m);
              p1.push(a[i][0]);
          
      }
      end= p1.top();
      while(1)
      {
          member temp= p.top();
          p.pop();
          start= temp.val;
          cout<<"\n start "<<start<<" end "<<end<<"\n";
          if(maxstart==-1 && maxend==-1 )
          {
             maxend= end;
             maxstart= start;
             cout<<"\n maxstart "<<maxstart<<" maxend "<<maxend<<"\n";
             
          }
          else
          {
             if(maxend- maxstart+1 > end-start+1)
             {
              maxend= end;
              maxstart= start;
              cout<<"\n maxstart "<<maxstart<<" maxend "<<maxend<<"\n";
             }
          }
          int row= temp.row1;
          int col= temp.col1;
          
          if(col>=n) break;
          member m1(a[row][col+1], row, col+1);
          p.push(m1);
          if(a[row][col+1] > end)
          end = a[row][col+1];
          
      }
      cout<<maxstart<<" "<<maxend<<"\n";
      


}

int main()
{
  int n,k;
  cin>>n>>k;
  int a[10][10];
  for(int i=0; i<k; i++)
  {
    for(int j=0; j<n; j++)
    {
      cin>>a[i][j];
    }
  }
  findSmallestRange(a,n,k);
}