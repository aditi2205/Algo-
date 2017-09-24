#include <iostream>
#include<bits/stdc++.h>
#include <numeric>
using namespace std;


vector<vector<int> > anagrams(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<string> arr;
    for(int i=0; i<A.size(); i++)
    arr.push_back(A[i]);
    
    for(int i=0; i<arr.size(); i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
        cout<<endl;
    }
    
    map<string, vector<int> > m;
    
    for(int i=0; i<arr.size(); i++)
    {
       if(m.find(arr[i])!= m.end())
       {
         m[arr[i]].push_back(i+1);
       }
       else
       {
         vector<int> ans;
         m.insert(make_pair(arr[i], ans));
         m[arr[i]].push_back(i+1);
       }

    }
    
    vector<vector<int> >res;
    map<string, vector<int> >::iterator it;
    for(it= m.begin(); it!=m.end(); it++)
    {
        res.push_back(it->second);
        cout<<it->first<<":";
        for(int i=0; i<it->second.size(); i++)
            cout<<it->second[i]<<" ";
    }
    cout<<endl;
    
    return res;
    
}
vector<int> twoSum(const vector<int> &arr, int target) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans, ans1;
    map<int, int> m;
    int n= arr.size();
    for(int i=0; i<n; i++)
    {
        m.insert(make_pair(arr[i], i+1));
    }
    int start=-1, end=-1;
    
    for(int i=0; i<n; i++)
    {
        if(m.find(target-arr[i])!= m.end() && m[target-arr[i]]>i  )
        {
            cout<<"found";
            int a= i+1;
            int b= m[target-arr[i]];

            if(start==-1 && end==-1)
            {
                start= a;
                end= b;
            }
            else
            {
                if(end>b)
                {
                    start= a;
                    end= b;
                }
                else if(end==b)
                {
                    if(start > a)
                    {
                        start= a;
                        end= b;
                    }
                }
            }
            

            
        }
        
    }
    if(start==-1 && end==-1)
    return ans1;
else
{

            ans.push_back(start);
            ans.push_back(end);
}
return ans;
}

int main()
{
    /*vector<string> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s; 
        v.push_back(s);
    }
    vector<vector<int> > ans = anagrams(v);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
*/
     vector<int> arr, res;
     int n, target;
     cin>>n>>target;
     for(int i=0; i<n; i++)
    {
        int s;
        cin>>s; 
        arr.push_back(s);
    }
res= twoSum(arr, target);
for(int i=0; i<res.size(); i++)
cout<<res[i]<<" ";

}