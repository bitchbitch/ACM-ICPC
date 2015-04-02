// File Name: hust1017.cpp
// Author: darkdream
// Created Time: 2014年10月04日 星期六 16时47分57秒

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
const int maxnode = 100010;
const int MaxM = 1010;
const int MaxN = 1010;
using namespace std;
struct DLX
{
    int n ,m ,size;
	int L[maxnode],R[maxnode],U[maxnode],D[maxnode],Row[maxnode],Col[maxnode];
	int ansd,ans[MaxN];
	int H[MaxN],S[MaxM];
	void init(int _n,int _m)
    {
        n = _n;
        m = _m;
        for(int i = 0;i <= m;i++)
        {
            S[i] = 0; // S 代表的是每一列的颜色
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
		}
        R[m] = 0; L[0] = m;
        size = m;
        for(int i = 1;i <= n;i++)
            H[i] = -1;  //  H[i]  代表第I 行的头
    }
    void Link(int r,int c)
    {
        ++S[Col[++size]=c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0)H[r] = L[size] = R[size] = size;
        else
        {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size; // 插入到  H[r] 的右边
        }
    }
    void remove(int c) //列为单位，横向
    {
        L[R[c]] = L[c]; R[L[c]] = R[c];
        for(int i = D[c];i != c;i = D[i])
            for(int j = R[i];j != i;j = R[j])
            {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]];
            }//删除一列，k行
    }
    void resume(int c)
	{
        L[R[c]] = R[L[c]] = c;
		for(int i = U[c];i != c; i = U[i])
			for(int j = L[i];j != i ;j = L[j])
			{
			     U[D[j]] = j;
				 D[U[j]] = j;
				 ++S[Col[j]];
			}
	}
	bool Dance(int d)
	{
	   if(R[0] == 0 )
	   {
	      ansd = d; //答案长度
		  return true;
	   }
	   int c = R[0];
	   for(int i = R[c];i != 0 ;i = R[i])
           if(S[i] < S[c])
                c = i ; 
       remove(c);
	   for(int i = D[c]; i != c;i = D[i])
	   {
	       ans[d] = Row[i];
           for(int j = R[i]; j != i ;j = R[j])  remove(Col[j]);
		   if(Dance(d+1)) return true;
		   for(int j = L[i]; j != i ;j = L[j])  resume(Col[j]);
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
      int num, j; 
	  for(int i = 1;i <= n;i ++)
	  {
	    scanf("%d",&num);
		while(num--)
		{
		  scanf("%d",&j);
		  g.Link(i,j);
		}
	  }
	  if(!g.Dance(0)) printf("NO\n");
	  else{
	    printf("%d ",g.ansd);
		for(int i = 0;i < g.ansd;i ++)
		  printf(" %d",g.ans[i]);
	    printf("\n"); 
	  }
	  
   }
return 0;
}
