// File Name: contact.c
// Author: darkdream
// Created Time: 2014年01月14日 星期二 20时22分24秒
/*
ID: dream.y1
PROG: contact
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a,b,n;
char str[200004];
int num[200004];
int hs[14][10001];
struct node
{
  int l,v;
}now;
int solve(int b,int e)
{
   int k = 0 ; 
   for(int i = b; i <= e; i ++)
   {
	 k = k * 2 + num[i];
   }
   return k ; 

}
struct node1{
  int l;
  int v;
  int t;
}ans[120000];
int cmp(const void * a ,const void * b)
{
  if((*(node1 *)b).t == (*(node1*)a).t)
	  return (*(node1 *)a).l - (*(node1 *)b).l;
  else return ((*(node1 *)b).t - (*(node1*)a).t);
}
void print(int v,int l)
{
     int t[12];
	 int tn = 0; 
	 while(v)
	 {
	    tn ++; 
		t[tn] = v%2;
		v = v/2;
	 }
	 for(int i = 1;i <= l-tn;i ++)
		 printf("0");
	 for(int i = tn ;i >=1  ;i --)
		 printf("%d",t[i]);
}
int main(){
  freopen("contact.in","r",stdin);
  freopen("contact.out","w",stdout);
  scanf("%d %d %d",&a,&b,&n);
  int len = 1 ; 
  while(scanf("%1d",&num[len]) != EOF)
  { 
     len ++;
  }
  len --;
  memset(hs,0,sizeof(hs));
  ans[0].t = 0 ; 
  
  
  for(int i = a; i <= len;i ++)
  { 
     int temp = solve(i-a+1,i);	 
     hs[a][temp] ++;
	 for(int j = i+1;j <= i+(b-a) && j <= len ;j ++)
	 {
	   temp = temp * 2 + num[j];
	   hs[a+j-i][temp] ++;
	  //printf("%d\n",temp);
	 }
  }
  int k = 0;
  for(int i = 1;i <= 12;i ++)
  {
    for(int j = 0;j <= 10000 ;j ++)
    {
	  if(hs[i][j])
	  {
	    k ++;
		ans[k].l = i ; 
		ans[k].v = j; 
		ans[k].t = hs[i][j];
	  }
	}
  }
  qsort(ans+1,k,sizeof(node1),cmp);
  int tt = 0;
  int pp = 0; 
  for(int i =1 ;i <= k;i ++)
  {
      if(ans[i].t != ans[i-1].t)
	  {
		   tt++;
		   if(tt == n +1)
			   break;
          
		  if(i != 1)
			  printf("\n");
	       printf("%d",ans[i].t);
	       pp = -1 ; 
	  }
	  pp++;
      if(pp % 6 == 0  )
		  printf("\n");
	  if(pp % 6 != 0)
	   printf(" ");
	  print(ans[i].v,ans[i].l);
	  
  }
  printf("\n");
 // printf("%d\n",hs[2][0]);
return 0 ;
}
