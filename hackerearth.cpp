#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first<b.first;
}
void countquadrant(char s[], int n)
{
    vector<pair<int, int> > v;
    int counts=0;
      int i=0;
      while(i<n)
      {
        int j= i+1;
        while(j<n)
        {
            if(s[i]==s[j])
            {
                v.push_back(make_pair(i,j));

            }
            j++;
        }
        i++;
      }

  
    sort(v.begin(), v.end(), comp);
   /* for(int i=0; i<v.size(); i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
*/
    for(int i=0; i<v.size(); i++)
    {
        for(int j=i+1; j<v.size(); j++)
        {
            int a= v[i].first;
            int c= v[i].second;
            int b= v[j].first;
            int d= v[j].second;
            
            if(a<c && b<d && a<b && c<d && a<d && b<c)
            {
                //cout<<"\n"<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
                counts++;
            }
        }
    }
    cout<<counts;
  }
int main()
{
    
    int n;
    cin>>n;
    char s[n];
    cin>>s;
    //cout<<s;

   
     countquadrant(s,n);
    return 0;
}
