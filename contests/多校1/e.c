// File Name: e.c
// Author: darkdream
// Created Time: 2013年07月25日 星期四 10时17分58秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int a[100005];
int stackup[100005];
int stacklow[100005];
int ans[100005];
int toplow = 0 ;
int topup = 0 ; 
int  update(int stack[],int top,int temp)
{
    int low = 1; 
    while(low <= top)
	{
	  int mid = (low + top) / 2;
	  if(temp > stack[mid])
	  {
	    low = mid + 1; 
	  }
	  else 
	  {
	    top = mid - 1;   
	  }
	}
   return low;
}

int find(int stack[],int top,int temp)
{
  int low  = 1 ;
  while(low <= top)
  {
    int mid = (low + top)/2;
	if(stack[mid] >= temp )
	{
	   top = mid - 1; 
	}
	else 
	{
	   low = mid + 1 ; 
	}
  }
  return low;
	return 1;
}

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int t ;
   scanf("%d",&t);
   while(t--)
   {
     int n ;
	 int max  = 0 ; 
	 memset(stackup,0,sizeof(stackup));
	 memset(stacklow,0,sizeof(stacklow));
	 memset(a,0,sizeof(a));
	 memset(ans,0,sizeof(ans));
	 scanf("%d",&n);
	 toplow = 0 ;
	 topup = 0 ;
	 for(int i =1 ;i<= n;i ++)
	   scanf("%d",&a[i]);
	 int ans1 , ans2 ;
     for(int i = n;i >= 1 ;i --)
	 { 

		int l1,l2 ;
		 
		if(a[i] >= stackup[topup] )
		{
		   topup ++ ; 
		   stackup[topup] = a[i];
		}
		else
		{
          int r = update(stackup,topup,a[i]);
		  stackup[r] = a[i];
		  ans1 = r;
		}
		l1 =ans1 - find(stackup,ans1,a[i]) - 1;
	   
       
		if((-a[i]) >= stacklow[toplow] )
		{
		   toplow ++ ; 
		   stacklow[toplow] = -a[i];
		}
		else
		{
          int r = update(stacklow,toplow,-a[i]);
		  stacklow[r] = -a[i];
		  ans2 = r;
		}
		l2 =ans2 - find(stacklow,ans2,-a[i]) - 1;
        
		if(ans2 - l2 + ans1 > ans1 - l1 + ans2)
			ans[i] = ans2 - l2 + ans1 - 1;
		else
			ans[i] = ans1 - l1 + ans2 - 1;
	 }
	 for(int i = 1;i <= n;i ++)
		 if(ans[i] > max )
			 max = ans[i];
    printf("%d\n",max);
   }
return 0 ;
}
