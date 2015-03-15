// File Name: uva548.c
// Author: darkdream
// Created Time: 2013年05月19日 星期日 19时52分46秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int a[10005];
int b[10005];
int maxstep,minnum;
void find(int ai , int aj ,int  bi,int bj, int step)
{
   if(ai == aj)
   {
     if(step +a[ai] < maxstep)
	 { 
	   maxstep = step +a[ai];
	   minnum = a[ai];
	 }
	 if(step +a[ai] == maxstep && a[ai] <minnum)
		 minnum = a[ai];
	 return ;
   }
   int i ;
   for(i = ai; i <= aj ;i ++)
   {
      if(a[i] == b[bj])
		  break;
   }
   if(i!= ai)
   {
     find(ai,i-1,bi,bi+(i-1-ai),step+a[i]);

   }
   if(i!= aj)
   {
     find(i+1,aj,bi+(i-ai),bj-1,step+a[i]);
   }
 return;
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int temp ;
   while(scanf("%d",&temp) != EOF)
   {
	maxstep =INT_MAX;
	minnum = INT_MAX;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
    int t ;
	char c;
	c = getchar();
	t = 1;
	a[t] = temp;
	while(1)
	{
		if(c == '\n')
			break;
		t++;
		scanf("%d",&a[t]);
		c = getchar();
	}
	
	for(int i = 1;i <= t; i ++)
		scanf("%d",&b[i]);
	find(1,t,1,t,0);
	printf("%d\n",minnum);
   }
return 0 ;
}
