// File Name: 7.3.1.cpp
// Author: darkdream
// Created Time: 2013年09月09日 星期一 09时02分53秒

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

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
using namespace std;
void print_subset(int n , int *A,int cur){
    for(int i = 1 ;i < cur; i ++) printf("%d ",A[i]);
	printf("\n");
	int s = A[cur-1]+1;
	for(int i = s;i <= n;i ++)
	{
	    A[cur] = i ; 
		print_subset(n,A,cur+1);
	}
}
int a[100];
int main(){
	int n ; 
	scanf("%d",&n);
	print_subset(n,a,1);

return 0;
}
