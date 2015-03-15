// File Name: uva10474.c
// Author: darkdream
// Created Time: 2013年02月24日 星期日 19时29分10秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[10001];
int main(){

 //   freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  int n , m  , k = 1;
  while(scanf("%d %d",&n,&m) != EOF)
  {  
	 if(n == 0 && m== 0)
		 break;
	  memset(a,0,sizeof(a));
	  printf("CASE# %d:\n",k);
	  for (int i = 0 ;i <  n ;i++)
	{	int temp;
		scanf("%d",&temp);
		a[temp] ++;

  
	}
	for(int i = 0 ;i< m; i++)
	{
	  int t ;
	  scanf("%d",&t);
	  if(a[t] == 0)
		  printf("%d not found\n",t);
	  else
	  {
		int sum = 0 ;
	    for(int i = 0;i < t ;i++)
			if(a[i]!= 0 )
				sum += a[i];
		 sum = sum+1;
		printf("%d found at %d\n",t,sum);
	  
	  }
	
	}
		k ++;
  }
return 0 ;
}
