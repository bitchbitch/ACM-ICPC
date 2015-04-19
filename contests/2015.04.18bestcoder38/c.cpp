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
int c[6][64];
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
int count(int k ){
   while(k != -1)
   {
	   int ok1 = 0;
	   int ok2 = 0;
	   if(c[1][k] != c[3][k])
	   {
			if(c[1][k] == 0)
				ok1 = 1; 
			else ok1 = 2; 
	   }
	   if(c[2][k] != c[4][k])
		   if(c[2][k] == 1)
			   ok2 = 1;
		   else ok1 = 2; 
	   if(ok1 == 0 || ok2 == 0 )
	   {
		 if(ok1 == 0)
		 {
			 if(ok2 == 1)
				 return 2;
			 else if(ok2 == 2)return 1; 
		 }else {
			 if(ok1 == 1 )
				 return 1; 
			 else if(ok1 == 2) return 2 ;
		 }
	   }
	   k -- ;
   }
   return 1; 
}
void solve(int k ){
	 if(k == -1)
		 return ;
	 if(c[1][k] == c[2][k] && c[3][k]  == c[4][k]){
		if(c[1][k] == c[3][k]){
			c[5][k] = 0;
		}else{
			c[5][k] = 1; 
		}
	//	printf("1 %d\n",k);
	 }else 
     if(c[2][k] == 1 && c[1][k] == 0 && c[3][k]  == 0&& c[4][k] == 0 ){
		 c[5][k] = 1;
		 for(int i = 0 ;i < k ;i ++)
			 c[1][i] = 0 ; 
	//	printf("2 %d\n",k);
	 }else
     if(c[2][k] == 1 && c[1][k] == 0 && c[3][k]  == 1&& c[4][k] == 1 ){
		 c[5][k] = 1;
		 for(int i = 0 ;i < k ;i ++)
			 c[2][i] = 1 ; 
	//	printf("3 %d\n",k);
	 }else 
     if(c[2][k] == 0 && c[1][k] == 0 && c[3][k]  == 0 && c[4][k] == 1){
		 c[5][k] = 0;
		 for(int i = 0 ;i < k ;i ++)
			 c[4][i] = 1 ; 
	//	printf("4 %d\n",k);
	 }else 
     if(c[2][k] == 1 && c[1][k] == 1 && c[3][k]  == 0 && c[4][k] == 1){
		 c[5][k] = 0;
		 for(int i = 0 ;i < k ;i ++)
			 c[3][i] = 0 ; 
	//	printf("5 %d\n",k);
	 }else{
		 //	printf("6 %d\n",k);
		 if(k == 0)
		 {
			 c[5][k] = 0; 
			 return ;
		 }
		 int chose = count(k-1);
			// printf("****t = %d %d %d %d\n",t,chose,lx,ly);
			 if(chose == 1)
			 {
				 for(int i = 0 ;i < k;i ++){
					 c[2][i] = c[4][i] = 1; 	
				 }
			 }else if(chose == 2 ){
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
	freopen("in","r",stdin);
	scanf("%d",&t);
	freopen("out","w",stdout);
	for(int ca = 1; ca <= t; ca ++){
		memset(c,0,sizeof(c));
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);	
		change(l1,1);
		change(r1,2);
		change(l2,3);
		change(r2,4);

	/*	printf("\n");
	 for(int i = 1;i <= 4; i ++)
	 {
		for(int j = 20;j >= 0; j --)
			 printf("%d ",c[i][j]);
		printf("\n");
	 }*/
	solve(35);
		LL t =1 ; 
		LL sum = 0 ; 
		printf("Case #%d: ",ca);
		for(int i = 0;i <= 35;i ++){
		     if(c[5][i]) 
				 sum += t; 
			 t *= 2; 
		}
	
	/*	printf("\n");
	 for(int i = 1;i <= 4; i ++)
	 {
		for(int j = 20;j >= 0; j --)
			 printf("%d ",c[i][j]);
		printf("\n");
	 }*/
		printf("%lld\n",sum);
	}
return 0;
}
