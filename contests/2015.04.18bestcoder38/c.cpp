// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年04月18日 星期六 19时25分11秒

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
int l1,l2,r1,r2;
double c[6][64];
void change(int n,int k )
{
  int  t = -1;
  while(n)
  {
	 t ++ ; 
     c[k][t] = n % 2 ;
	 n /= 2; 
  }
}
void solve(int k ){
	 if(c[1][k] == c[2][k] && c[3][k]  == c[4][k]){
		if(c[1][k] == c[3][k]){
			c[5][k] = 0;
		}else{
			c[5][k] = 1; 
		}
	 }else 
     if(c[2][k] == 1 && c[1][k] == 0 && c[3][k]  == 0&& c[4][k] == 0 ){
		 c[5][k] = 1;
		 for(int i = 0 ;i < k ;i ++)
			 c[1][i] = 0 ; 
	 }else
     if(c[2][k] == 1 && c[1][k] == 0 && c[3][k]  == 1&& c[4][k] == 1 ){
		 c[5][k] = 1;
		 for(int i = 0 ;i < k ;i ++)
			 c[2][i] = 1 ; 
	 }else 
     if(c[2][k] == 0 && c[1][k] == 0 && c[3][k]  == 0 && c[4][k] == 1){
		 c[5][k] = 0;
		 for(int i = 0 ;i < k ;i ++)
			 c[4][i] = 1 ; 
	 }else 
     if(c[2][k] == 1 && c[1][k] == 1 && c[3][k]  == 0 && c[4][k] == 1){
		 c[5][k] = 0;
		 for(int i = 0 ;i < k ;i ++)
			 c[3][i] = 0 ; 
	 }else{
		if(k == 0)
		{
			c[5][k] = 0; 
			return ;
		}
	    int lx = 0 ; 
		int ly = 0 ;
		int ok1 = 0; 
		int ok2 = 0;
		for(int i = 0 ;i < k ;i ++)
		{
		   if(c[1][i] != c[3][i])
		   {
			   if(c[1][i] == 1)
			   {
			       ok1 = 0 ;
				   lx = i ; 
			   }else{
			       ok1 = 1; 
				   lx = i; 
			   }
			   break;
		   }
		}
		for(int i = 0 ;i < k ;i ++){
			if(c[2][i] != c[4][i]){
			   if(c[2][i] == 1){
				  ok2 = 1; 
				  ly = i ; 
			   }else{
				  ok2 = 0;
				  ly = i ; 
			   }
			   break;
			}
		}
		int chose = 0 ; 
		if(ok1 && ok2){
			if(lx < ly)
			{
			  chose = 2; 
			}else 
			  chose = 1 ;
		}else if(ok1 && !ok2){
	        chose = 1;	
		}else if(!ok1 && ok2){
		    chose = 2; 
		}else {
		   if(lx < ly)
			   chose = 1; 
		   else chose = 2; 
		}
		if(chose == 1)
		{
			for(int i = 0 ;i < k;i ++){
			    c[2][i] = c[4][i] = 1; 	
			}
		}else{
			for(int i = 0 ;i < k ;i ++){
				c[1][i] = c[3][i] = 0;
			}
		}
		c[5][k] = 0 ; 
	 }
	 solve(k-1);
}
int main(){
	int t;  
	scanf("%d",&t);
	for(int ca = 1; ca <= t; ca ++){
		memset(c,0,sizeof(c));
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);	
		change(l1,1);
		change(r1,2);
		change(l2,3);
		change(r2,4);
		LL t =1 ; 
		LL sum = 0 ; 
		printf("Case #%d: ",ca);
		for(int i = 0;i <= 32;i ++){
		     if(c[5][i]) 
				 sum += t; 
			 t *= 2; 
		}
		printf("%lld\n",sum);
	}
return 0;
}
