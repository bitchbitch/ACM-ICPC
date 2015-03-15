// File Name: sbt.cpp
// Author: darkdream
// Created Time: 2014年04月25日 星期五 19时50分46秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<climits>

using namespace std;

#define maxn 1000005
int key[maxn],left[maxn],right[maxn],s[maxn];
void RR(int t)
{
	int k = left[t];
	left[t] = right[k];
	right[k] = t ; 
	s[k] = s[t];
	s[t] = s[left[t]] + s[right[t]];
	t = k ; 
}
void LR(int t)
{
	int k = right[t];
	right[t] = left[t];
	left[k] = t ; 
	s[k] = s[t];
	s[t] = s[left[t]] + s[right[t]];
	t = k ; 
}
void Maintain(int t)
{
	if(s[left[left[t]]] > s[right])
	{
		RR(t);
		Maintain(right[t]);
		Maintian(t);
		return ; 
	}
	if(s[right[lert[t]]] > s[right[t]])
	{
		LR(left[t]);
		RR(t);
		Maintain(left(t));
		Maintain(right(t));
		Maintain(t);
		return ; 
	}
	if(s[right[right[t]]] > s[left]){
		LR(t);
		Maintain(left[t]);
		Maintain(t);
		return ; 
	}
	if(s[left[right]] > s[left[t]])
	{
		RR(right[t]);
		LR(t);
		Maintain(left[t]);
		Maintain(right[t]);
		Maintain(t);
	}

}

void Simple-Insert(int t, int  v)
{
	if(t == 0 )
		t = NEW-NODE(v);
	else 
	{
		s[t] = s[t] + 1; 
		if(v < key[t])
			Simple-Insert(left[v],v);
		else 
			Simple-Insert(right[t],v);
	}
}
void Insert(int t, int v){
	if(t == 0 )
		t = NEW-NODE(v);
	else 
	{
		s[t] = s[t] + 1; 
		if(v < key[t])
			Simple-Insert(left[v],v);
		else 
			Simple-Insert(right[t],v);
		Maintain(t);
	}
}
int main(){
	//freopen("/home/darkdream/problem/input.txt","r",stdin);
	//freopen("/home/darkdream/problem/output.txt","w",stdout);

	return 0;
}
