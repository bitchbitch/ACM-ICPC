// File Name: c.c
// Author: darkdream
// Created Time: 2014年03月20日 星期四 00时57分12秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int n , k ; 
struct node{
  int num ;
  int v; 
}a[100005],b[1000006],f[100005];
int hs[100005];
int num[100005];
int ans = 0 ; 
void solve(int k)
{

   for(int i = f[k+1].num; i <=f[k+1].v ;i ++)
   {
      ans ++ ;
	  b[ans].num = a[f[k].v].num;
	  b[ans].v = a[i].num;
   }

}
int cmp(const void * a ,const void *b)
{
   return (*(node *)a).v - (*(node *)b).v;
}
int fnum = 0 ; 
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   scanf("%d %d",&n,&k);
   int ok = 1 ;
   memset(hs,0,sizeof(hs));
   for(int i = 1;i <= n;i ++)
   {	  scanf("%d",&a[i].v);
          a[i].num = i ;
		  hs[a[i].v] = 1; 
   }
   if(!hs[0])
	   ok = 0 ; 
   for(int i = 1; i <= n;i ++)
	   if(hs[i-1] && hs[i+1] && !hs[i])
		   ok = 0 ; 
   fnum ++ ;
   f[fnum].num = 1;
   for(int i = 2;i <= n; i ++)
   {
     if(a[i].v != a[i-1].v)
	 {
	   f[fnum].v = a[i-1].num;
	   fnum ++ ;
	   f[fnum].num = a[i].num; 
	 }
   }
   f[fnum].v = n; 
   for(int i = 1;i <= fnum- 1;i ++)
   {
      solve(i);
   }
   if(!ok )
   {
	   printf("-1\n");
       return 0 ;
   }
     printf("%d\n",ans);
	 for(int i =1 ;i <= ans;i ++)
	 printf("%d %d\n",b[i].num,b[i].v);
return 0 ;
}
