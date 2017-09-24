/**
 * @input A : Integer
 * @input B : Integer
 * 
 * @Output Integer
 */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 int count=0;
 void findnumbers(int n, int sum , int val)
 {
     int cursum+=val;
     if(val>9)
     return;
     if(cursum==sum && n==0)
     {
         count++;
         return;
     }
     if(cursum==sum && n==1)
     {
         count++;
         return;
         //because we can place trailing zero
     }
     findnumbers(n-1, sum, val);
     findnumbers(n-1, sum, val+1);
 }
int solve(int N, int S) {
    findnumbers(N,S,1);
    return count;
    
}
