#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N=1000;

int arr[N]={1,2,3,4,5};
int tree[3*N];

int left(int i) { return i<<1;}
int right(int i) {return (i<<1)+1;}

void build(int root, int be, int en)
{
	//root is an index
	if(be>en)
		return;

	if(be==en)
	{
		tree[root]= arr[be];
		return;
	}
	int mid= (be+en)/2;
	build(left(root), be, mid);
	build(right(root), mid+1, en);

	tree[root]= min(tree[left(root)], tree[right(root)]);
}

//be and en is search range of tree and i and j are query range

int search(int root, int be, int en, int i, int j)
{
	if(be>en)
		return 0;

	if(be>=i && j>=en)
	{
		return tree[root];
	}
	int mid= (be+en)/2;
	if(i<=mid && j<=mid)
	{
		return search(left(root), be, mid, i,j);
	}
	else if(i>mid && j>mid)
	{
		return search(right(root), mid+1, en, i,j);
	}
	int leftans= search(left(root), be, mid, i, j);
	int rightans= search(right(root), mid+1, en, i,j);

	return min(leftans, rightans);
}

void update(int root, int be, int en, int index, int val)
{
	if(be>en)
		return;
	if(be==index && en== index)
	{
		tree[root]=val;
		return;
	}

	int mid= (be+mid)/2;
	
	 if(index<=mid)
	{
		update(left(root), be, mid, index, val);
	}
	else if(index>mid)
	{
		update(right(root), mid+1, en, index, val);
	}
	tree[root]= min(tree[left(root)], tree[right(root)]);
}
int main()
{
	build(1,0,4);
  cout<<search(1,0,4,0,4);//1
  cout<<search(1,0,4,3,4);//4
  cout<<search(1,0,4,2,3);//3
  cout<<search(1,0,4,1,4);//2

  update(1,0,4,3,-100);
   build(1,0,4);
  cout<<search(1,0,4,2,3);//2

}