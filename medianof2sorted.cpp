#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int median( int a[], int n)
{
	if(n%2==0)
	{
		return (a[n/2-1]+a[n/2])/2;
	}
	else
		return (a[n/2]);
}
int computemedian(int a[], int b[])
{
	int p= max(a[0], b[0]);
	int q= min(a[1], b[1]);
	return (p+q)/2;
}

/*int finalmedian(int a[], int b[], int ab, int ae, int bb,int be)
{
	int size_a= ae-ab+1;
	int size_b= be-bb+1;
	int m1= findmedian(size_a,a);
	int m2= findmedian(size_b,b);

     if(m1==m2)
     	return m1;
     if(size_a==2 && size_b==2)
     	return computemedian(a,b);
     else if(m1>m2)
     {
         return finalmedian(a,b,ab,size_a/2, size_b/2, be);
     }
     else if(m1<m2)
     {
     	return finalmedian(a,b,size_a/2, ae, bb, size_b/2);
     }
}*/
int getMedian(int ar1[], int ar2[], int n)
{
    /* return -1  for invalid input */
    if (n <= 0)
        return -1;
    if (n == 1)
        return (ar1[0] + ar2[0])/2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;
 
    int m1 = median(ar1, n); /* get the median of the first array */
    int m2 = median(ar2, n); /* get the median of the second array */
 
    /* If medians are equal then return either m1 or m2 */
    if (m1 == m2)
        return m1;
 
    /* if m1 < m2 then median must exist in ar1[m1....] and
        ar2[....m2] */
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n/2 - 1, ar2, n - n/2 +1);
        return getMedian(ar1 + n/2, ar2, n - n/2);
    }
 
    /* if m1 > m2 then median must exist in ar1[....m1] and
        ar2[m2...] */
    if (n % 2 == 0)
        return getMedian(ar2 + n/2 - 1, ar1, n - n/2 + 1);
    return getMedian(ar2 + n/2, ar1, n - n/2);
}
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	int b[n+1];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		cin>>b[i];
	

	int m3= getMedian(a,b,n);
	cout<<m3;



}