// File Name: g.c
// Author: darkdream
// Created Time: 2013年07月17日 星期三 13时03分10秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
struct node
{
	int num ;
	int value;
	int limit;
	int lnum ;
}d[300005];
int cmp(const void * b,const void *a)
{
	return (*(node *)a).value - (*(node*)b).value;
}
int ans[300005];
int sum[300005];
int up;
int lowbit(int x)
{
   return x & (-x);
}
int Tsum(int k )
{
   int Sum =0 ;
   while(k >0 )
   {
     Sum += sum[k];
	 k -= lowbit(k);
   }
   return Sum;
}
void update(int k)
{
  while(k <= up)
  {
     sum[k] += 1;
	 k += lowbit(k);
  }
}
struct nodep
{
	int num ;
	int limit;
}p[300005];
int cmp1(const void * a ,const void * b)
{
	return *(int *)a -*(int *)b;
}
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int n;
	while(scanf("%d",&n) != EOF)
	{
		memset(ans,0,sizeof(ans));
		memset(d,0,sizeof(d));
		memset(p,0,sizeof(p));
		getchar();
		int j = 0 ;
		int k = 0 ;
		for(int i = 1;i < n;i ++)
		{
			char c;
			int temp;
			scanf("%c %d",&c,&temp);
			getchar();
			if(c == 'p')
			{
				k ++;
				p[k].num = j; 
				p[k].limit = temp ;
			}
			else if(c == 'd') 
			{
				j ++ ; 
				d[j].value = temp;
				d[j].num = i; 
			}
		}
		up = k;
		for(int i= k -2 ;i >= 1; i --)
		{
			if(p[i].limit > p[i+1].limit)
				p[i].limit = p[i+1].limit;
		}
      
		
		for(int i =1 ;i <= k ;i ++)
			printf("%d ",p[i].limit);
		printf("\n");
		//print about p 
		
		
		int t = 0 ;
		for(int i = 1;i < k; i ++)
		{
			for(int s = p[i].num ; s > t; s --)
			{
				d[s].limit = p[i].limit;
				d[s].lnum = i ;
			}
			t = p[i].num;
		}

		for(int i = p[k].num ; i > t; i --)
		{
			d[i].limit = 1000000;
			d[i].lnum = k ;
		}
		if(j != 0 )
			qsort(d+1,p[k-1].num,sizeof(node),cmp);
		int step = 0;
		int sum  = 0;
		for(int i =1 ; i<= j; i ++)
		{
           if(Tsum(d[i].lnum) + 1 < d[i].limit  || d[i].lnum == k )
		   {
			  if(d[i].num == 16)
			  {
			    printf("****: %d   %d\n",Tsum(d[i].lnum),d[i].limit);
			  }
		      update(d[i].lnum);
			  step++;
			  sum += d[i].value;
			  ans[step] = d[i].num +1 ;
			  
		   }
		}
		if(step <  p[k].limit)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",sum);
			printf("%d\n",step);
			if(step != 0 )
				qsort(ans+1,step,sizeof(int),cmp1);
			for(int i=1 ;i <= step ;i ++)
				printf("%d ",ans[i]);
			if(step != 0 )
				printf("\n");
		}
	}


	return 0 ;
}
