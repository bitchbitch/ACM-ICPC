/************************************************************
 * Author        : darkdream
 * Email         : darkdream1994@gmail.com 
 * Last modified : 2013-12-12 23:48
 * Filename      : prefix.cpp
 * Description   :
 * *********************************************************/
// File Name: prefix.cpp
// Author: darkdream
// Created Time: 2013年12月12日 星期四 23时01分29秒
/*
ID: dream.y1
PROG: prefix
LANG: C++
*/
#include<vector>
#include<list>
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

using namespace std;
char str1[200001];
int dp[200001];
int ans[200001][11];
char str[201][12];
int  p[201][12];
int k = 0;
int len[201];
int lens ;
void kmp()
{
 // int lens = strlen(str1);
  int q[201];
  memset(q,-1,sizeof(q));
  for(int i = 0;i < lens;i ++)
  {
     for(int j= 1;j <= k;j ++)
	 {
	     while(q[j] >= 0 && str[j][q[j]+1] != str1[i])
			 q[j] = p[j][q[j]];
		 if(str[j][q[j]+1] == str1[i] )
			 q[j] = q[j] + 1; 
		 if(q[j] == len[j] -1)
		 {
		     ans[i-len[j]+1][len[j]] = 1;
			 //printf("%d %d\n",i-len[j]+1,len[j]);
			 q[j] = p[j][q[j]];
		 }
	 }
  }

}
int main(){
   freopen("prefix.in","r",stdin);
 freopen("prefix.out","w",stdout);
 // printf("000");
   while(scanf("%s",str[++k]) != EOF)
   {
     if(strlen(str[k]) == 1 && str[k][0] == '.')
	 {
		 k --;
		 break;
	 }
	 len[k] = strlen(str[k]);
	 int s = -1;
	 p[k][0] = -1;
	 for(int i=  1;i < len[k];i ++)
	 {
	     while(s >= 0 && str[k][s+1] != str[k][i])
            s = p[k][s];
		 if(str[k][s+1] == str[k][i])
			  s = s + 1; 
		 p[k][i] = s; 
	 }
   }
   //printf("k = %d\n",k);
   char c;
   int temp = -1;
   while((c = getchar()) != EOF)
   {
	   if(c <= 'Z' && c >= 'A')
	    str1[++temp] = c; 
   }
   str1[++temp] = '\0';
   lens = temp;
 // printf("%d\n",lens);
  //puts(str1);
   kmp();
  for(int i = -1;i < lens ;i ++ )
   {
	if(dp[i] || i == -1 )
	{
      for(int j = 1;j <= 10 ;j ++)
	  {
	    if(ans[i+1][j])
			dp[i + j] = 1;
	  }
	}
   }
   for(int i = lens ;i >= 0 ;i --)
	   if(dp[i])
		{
		  printf("%d\n",i+1);
		  return 0;
		}
  printf("0\n");
return 0;
}
