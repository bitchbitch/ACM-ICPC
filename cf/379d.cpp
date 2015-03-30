// File Name: 379d.cpp
// Author: darkdream
// Created Time: 2015年03月30日 星期一 16时33分13秒

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
LL k , p, n , m ;
LL dp[100][5];
LL tmp[10];
LL ok  = 0 ; 
void print(char str[],LL num,LL len)
{
//	printf("%I64d %I64d\n",num,len);
    if(str[1] == 'C')
	{
	  for(LL i = 2;i <= 2*num;i +=2)
	  {
	     str[i] = 'A';
		 str[i+1] = 'C';
	  }
	  for(LL i = 2*num + 2;i <= len-1;i ++)
		  str[i] = 'Z';
	}else{
	  for(LL i = 1;i <= 2*num;i +=2)
	  {
	     str[i] = 'A';
		 str[i+1] = 'C';
	  }
	  for(LL i = 2*num + 1;i <= len-1;i ++)
		  str[i] = 'Z';
	}
	for(LL i = 1;i <= len ;i ++)
		printf("%c",str[i]);
	printf("\n");
}
LL solve(LL x , LL y , LL status)
{
  LL hehe = status; 
   memset(dp,0,sizeof(dp)) ;
   LL tt = 0 ; 
   memset(tmp,0,sizeof(tmp));
   while(status)
   {
	  tt ++ ; 
      tmp[tt] = status %2; 
	  status /= 2;
   }
   LL tx;
   LL ty;
   tx = ty = 0 ;
   if(tmp[2] && tmp[3])
	   tmp[4] = 1; 
   if(tmp[1])
   {
	  return 0;
      tx += 2;
   }
   if((tmp[2] || tmp[3]) && (tmp[2] != tmp[3]))
   {
	  tx ++;
	  ty ++ ;
   }
   if(tmp[2] && tmp[3])
   {
      tx += 2; 
	  ty +=2;
   }
   if(tmp[4]&& tmp[3] == 0)
   {
	  ty += 2 ;
   }
   if(x *2 + tx > n)
	   return 0 ; 
   if(y*2 + ty > m)
	   return 0;
  // printf("%I64d %I64d %I64d\n",x,y,status);
   memset(dp,0,sizeof(dp));
   dp[1][1] = x; 
   dp[2][1] = y;
   dp[3][1] = x+ y ;
   dp[3][3] = tmp[2]; 
   for(LL i = 4; i <= k ;i ++)
   {
       for(LL j = 1;j <= 5;j ++)
		   dp[i][j] += dp[i-1][j] + dp[i-2][j];
	   if(i % 2 == 0)
		   dp[i][4] += tmp[3];
	   else dp[i][5] += tmp[4]; 
   }
   LL tsum = 0 ; 
   for(LL j = 1;j<= 5;j ++)
	   tsum += dp[k][j];
  //printf("%I64d %I64d %I64d %I64d\n",tsum,x,y,hehe);
   if(tsum != p)
	   return 0 ;
   char ansa[105];
   char ansb[105];
   memset(ansa,0,sizeof(ansa));
   memset(ansb,0,sizeof(ansb));
   if(tmp[1])
   {
      ansa[1] = 'C'; 
	  ansa[n] = 'A';
   }
   if(tmp[2])
   {
      ansa[n] = 'A';
	  ansb[1] = 'C';
   }
   if(tmp[3])
   {
      ansa[1] = 'C';
	  ansb[m] = 'A';
   }
   if(tmp[4])
   {
      ansb[1] = 'C';
	  ansb[m] = 'A';
   }
   if(ansa[n] == '\0')
	   ansa[n] ='Z';
   if(ansb[m] == '\0')
	   ansb[m] ='Z';
   print(ansa,x,n);
   print(ansb,y,m);
   return 1;
}
int main(){
      scanf("%I64d %I64d %I64d %I64d",&k,&p,&n,&m);
	  for(LL i = 0;i <= n/2;i ++)
	  {
	      for(LL j = 0;j <= m/2;j ++)
		  {
			 for(LL s = 0 ; s<= 15; s ++)
		      if(solve(i,j,s))
				  return  0 ;
		  }
	  }
	  printf("Happy new year!\n");
return 0;
}
