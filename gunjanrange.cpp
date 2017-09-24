#include <bits/stdc++.h>
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

class compare1{
public:
  bool operator()( const member x, const member y) const
  {
    return x.val<y.val;
  }
};


void findSmallestRange(int arr[][10], int n, int k)
{
      //code here
     
    priority_queue< member, vector<member>, compare1 > maxh;
  priority_queue< member , vector<member>, compare >  minh;
     
      for(int i=0;i<k;i++){
        member obj(arr[i][0],i,0);
          maxh.push(obj);
          minh.push(obj);
          
      }
      
      int minrange=INT_MAX,maxrange=INT_MIN;
      
      member minhere=minh.top();
      member maxhere=maxh.top();
          
          if(minhere.val<minrange && maxhere.val>maxrange){
            
              minrange=  minhere.val;
              maxrange=  maxhere.val;
          
          }
          cout<<minrange<<" "<<maxrange<<":";
      
      while(1){
          
         
          member temp=minh.top();
          int listidx=minh.top().row1;
          int eleidx=minh.top().col1;
          
          if(eleidx>=n)
            break;
          
          minh.pop();
          member p=member(arr[listidx][eleidx+1],listidx,eleidx+1);
          
          minh.push(p);
          
          if(p.val > maxh.top().val){
              maxh.push(p);
          }          
          
          minhere=minh.top();
          maxhere=maxh.top();
          
          if(maxhere.val-minhere.val<maxrange-minrange){
              minrange=minhere.val;
              maxrange=maxhere.val;
          }
          
      }
      
      cout<<minrange<<" "<<maxrange<<"\n";
      
}




int main() {
  // your code goes here
  
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
  
  
  return 0;
}