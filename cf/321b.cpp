/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2015-03-31 11:10
 * Filename : 321b.cpp
 * Description :
 * *********************************************************/
// File Name: 321b.cpp
// Author: darkdream
// Created Time: 2015年03月31日 星期二 09时34分01秒

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
int n , m; 
int atk[105];
int atkn;
int def[105];
int defn; 
int matk[105];
int tatk[105];
int tatkn;
char str[100];
int mx;
int solve(int k)
{
    int ans  = 0 ;
	for(int i = 1;i<= k;i ++)
	{
	    if(matk[i] >= atk[k-i+1])
		{
		   ans += matk[i] - atk[k-i+1];
		}else{
		 return -1;
		}
	}
	mx = max(mx,ans);
	return ans;
}
int cmp(int a, int b)
{
   return a > b; 
}
multiset<int> num;
int main(){
	scanf("%d %d",&n,&m);	
	int ta; 
    for(int i = 1;i <= n;i ++)
	{
       scanf("%s",str);
	   scanf("%d",&ta);
	   
	   if(str[0] == 'D')
	   {
	     defn ++ ; 
		 def[defn] = ta;               
	   }
	   else{
	     atkn ++ ; 
		 atk[atkn] = ta; 
	   }
	}
	for(int i = 1;i <= m;i ++)
	{
	    scanf("%d",&matk[i]);
		num.insert(matk[i]);
	  // printf("%d %d\n",m,num.size());
	}
    sort(atk+1,atk+1+atkn);
	sort(matk+1,matk+m+1,cmp);
	for(int i = 1;i <= min(atkn,m); i++)
	{
        solve(i); 
	}
	if(m > atkn + defn)
	{
		set<int>::iterator tt;
		int ok = 1; 
		for(int i = 1;i <= defn; i ++)
		{
			tt = num.upper_bound(def[i]) ;
			if(tt == num.end()) 
			{
				ok = 0 ;
				break;
			}else{
				num.erase(tt);
			}
		}
		if(ok == 1)
		{
			m = 0 ;
			memset(matk,0,sizeof(matk));
			for(tt = num.begin();tt != num.end();tt ++)
			{
				m ++ ;
				matk[m] = *tt;
			}
			sort(matk+1,matk+m+1,cmp);
		    int hehe = solve(atkn);
			if(hehe != -1 )
			{
			   for(int i = atkn+1;i <= m;i ++)
			   {
			      hehe += matk[i];
			   }
			   mx = max(hehe,mx);
			}
		}
	}
	printf("%d\n",mx);
return 0;
}
