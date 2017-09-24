#include <iostream>
#include <math.h>
using namespace std;
int time_my=0;
 int cnt=0;
 
bool funct(int n, int ts, int tf, int s[100], int f[100], int d[100], int i){
 
 //	cout<<time_my<<" "<<i<<";;";
 
    if(time_my>tf)
        return false;
    if(time_my<=tf&&i>=n-1)
        return true;
 
    int time_prev=time_my;
    time_my+=ts;
 
    if(time_my>s[i]){
        int freq=ceil((time_my-s[i])/float(f[i]));
      //  cout<<"ceil"<<freq<<" ";
        time_my+=(s[i]+freq*f[i])-time_my;
    }
    else{
        time_my+=s[i]-time_my;
    }
 
    time_my+=d[i];
    cnt+=1;
 
    if(funct(n,ts,tf,s,f,d,i+1)){
        return true;
    }
    else{
    	cnt-=1;
        time_my=time_prev;
        
        if(time_my>s[i]){
            int freq=ceil((time_my-s[i])/float(f[i]));
            time_my+=(s[i]+freq*f[i])-time_my;
        }
        else{
            time_my+=s[i]-time_my;
        }
     
    time_my+=d[i];
 
        if(funct(n,ts,tf,s,f,d,i+1)){
            return true;
        }
 
        else
            return false;
        }
 
}
 
int main(){
 
 	int test;
cin>>test;

for(int t=0;t<test;t++){
 	time_my=0,cnt=0;
    int n,ts,tf;
    int s[100],f[100],d[100];
 
    cin>>n>>ts>>tf;
 
        for(int i=0;i<n-1;i++)
        {
            cin>>s[i]>>f[i]>>d[i];
        }
 
 
 	cout<<"Case #"<<t+1<<": ";
        if(funct(n,ts,tf,s,f,d,0))
        {
             cout<<cnt<<"\n";
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }
 }
 
}
