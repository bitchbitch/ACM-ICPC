// File Name: heapsort.cpp
// Author: darkdream
// Created Time: 2015年05月01日 星期五 14时53分05秒

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
#define LL long long
#define maxn 500000
using namespace std;
int heap[maxn];
int heapsz;
int L(int x){
	return 2 * x; 
}
int R(int x){
	return 2 * x  + 1; 
}
void max_heap(int i ){
	printf("%d\n",i);
   int mx = i ; 
   int l = L(i);
   int r = R(i);
   if(l <= heapsz && heap[l] > heap[i]){
		mx = l ; 
   }else mx = i ; 
   if(r <= heapsz && heap[r] > heap[mx])
	   mx = r; 
   if(mx != i ){
		swap(heap[i],heap[mx]);
		max_heap(mx);
   }
}
int main(){
	scanf("%d",&heapsz);
	for(int i = 1;i <= heapsz;i ++){
		scanf("%d",&heap[i]);
	}
	for(int i = heapsz/2; i >= 1 ;i --){
		max_heap(i);
	}
	printf("\n");;
	for(int i = 1;i <= heapsz;i ++)
		printf("%d ",heap[i]);
return 0;
}
