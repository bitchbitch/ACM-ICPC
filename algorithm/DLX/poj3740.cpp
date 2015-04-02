// File Name: poj3740.cpp
// Author: darkdream
// Created Time: 2014年10月04日 星期六 20时06分31秒

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

using namespace std;
const int maxnode = 50000;
const int MaxN = 18;
const int MaxM = 400;
struct DLX
{
    int n , m , size;
	int U[maxnode],D[maxnode],L[maxnode],R[maxnode],Row[maxnode],Col[maxnode];
	int H[MaxN],S[MaxM];
	void init(int _n,int _m)
	{
	   n = _n;
	   m = _m;
	   for(int i = 0 ;i <= m;i ++)
	   {
		   S[i] = 0 ; 
	       U[i] = i ; 
		   D[i] = i ; 
		   L[i] = i-1;
		   R[i] = i+1;
	   }
	   size = m ; 
	   L[0] = m; 
	   R[m] = 0 ;
	   memset(H,-1,sizeof(H));
	}
	void Link(int r, int c)
	{
	    ++S[Col[++size] = c];
		Row[size] = r; 
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c; 
		D[c] = size ;
	    if(H[r] < 0)  H[r] = L[size] = R[size] = size;
		else{
		  R[size] = R[H[r]];
		  L[R[H[r]]] = size;
		  L[size] = H[r];
		  R[H[r]] = size;
		}
	}
	void remove(int c)
	{
	  L[R[c]] = L[c];
	  R[L[c]] = R[c];
	  for(int i = D[c]; i != c ;i = D[i])
		  for(int j = R[i]; j != i ;j = R[j])
		  {
		       U[D[j]] = U[j];
			   D[U[j]] = D[j];
			   --S[Col[j]];
		  }
	}
	void resume(int c)
	{
       L[R[c]] = c; 
	   R[L[c]] = c; 
	   for(int i = D[c];i != c;i = D[i])
		   for(int j = R[i]; j != i ;j = R[j])
		   {
		      U[D[j]] = j ; 
			  D[U[j]] = j; 
              ++ S[Col[j]];
		   }
	}
	bool Dance()
	{
	   if(R[0] == 0 )
	   {
	     return true;
	   }
	   int c = R[0];
	   for(int i = R[c];i != 0 ;i = R[i])
		   if(S[i] < S[c])
			   c = i ; 
	   remove(c);
	   for(int i = D[c];i != c;i = D[i])
	   {
	       for(int j = R[i];j != i ;j = R[j]) remove(Col[j]);
		   if(Dance()) return true;
		   for(int j = R[i];j != i; j = R[j]) resume(Col[j]);
	   }
	   resume(c);
       return false;
	}
};

DLX g; 
int main(){
    int n , m ; 
	while(scanf("%d %d",&n,&m) != EOF)
	{
	   g.init(n,m);
	   int t ;
	   for(int i = 1;i <= n;i ++)
		   for(int j = 1;j <= m;j ++)
		   {
		      scanf("%d",&t);
			  if(t)
				g.Link(i,j);
		   }
	   if(g.Dance()) 
		   printf("Yes, I found it\n");
	   else printf("It is impossible\n");
	}
return 0;
}
