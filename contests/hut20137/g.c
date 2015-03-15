// File Name: g.c
// Author: darkdream
// Created Time: 2013年09月09日 星期一 13时45分49秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int a[200][200];
int n ;
int ok1()
{
	   for(int i = 1;i <= n;i ++)
	   {
		 int k = 2*i-1;
		 for(int j = 1;j <= k; j ++)
	     if(a[i][j] == 0 && a[i][j-1] == 1)
		 {
              k = 0 ;
			  return 0;
		 }
	   }
	   return 1; 
}
int ok2()
{
	   for(int i = 1;i <= n;i ++)
	   {
		 int k = 2*i-1;
		 for(int j = 1; j <= k; j++)
	     if(a[i][j] == 0 && a[i][j+1] == 1)
		 {
			  return 0;
		 }
	   }
	   return 1; 
}
int ok3()
{
	   for(int i = 1;i <= n;i ++)
	   {
		 int k = 2*i-1;
		 for(int j = 1; j <= k; j++)
	     if(a[i][j] == 0 )
		 {
              if(j % 2 == 1)
			  {
			     if(a[i][j-1] == 1)
				    return 0 ;
			  }
			  else
			  {
			      if(a[i-1][j-1] == 1)
					  return 0;
			  }
		 }
	   }
	   return 1; 
}
int ok4()
{
	   for(int i = 1;i <= n;i ++)
	   {
		 int k = 2*i-1;
		 for(int j = 1;  j <= k; j ++)
	     if(a[i][j] == 0 )
		 {
              if(j % 2 == 1)
			  {
			     if(a[i+1][j+1] == 1)
				    return 0 ;
			  }
			  else
			  {
			      if(a[i][j+1] == 1)
					  return 0;
			  }
		 }
	   }
	   return 1; 
}
int ok5()
{
	   for(int i = 1;i <= n;i ++)
	   {
		 int k = 2*i-1;
		 for(int j = 1; j <= k ; j ++)
	     if(a[i][j] == 0 )
		 {
              if(j % 2 == 1)
			  {
			     if(a[i][j+1] == 1)
				    return 0 ;
			  }
			  else
			  {
			      if(a[i-1][j-1] == 1)
					  return 0;
			  }
		 }
	   }
	   return 1; 
}
int ok6()
{
	   for(int i = 1;i <= n;i ++)
	   {
		 int k = 2*i-1;
		 for(int j = 1; j <= k; j ++)
	     if(a[i][j] == 0 )
		 {
              if(j % 2 == 1)
			  {
			     if(a[i+1][j+1] == 1)
				    return 0 ;
			  }
			  else
			  {
			      if(a[i][j-1] == 1)
					  return 0;
			  }
		 }
	   }
	   return 1; 
}
int main(){
     int t  = 0 ;
	 while(scanf("%d",&n)!= EOF && n)
	 {
	   int ok = 0 ;
	   memset(a,0,sizeof(a));
	   t++;
	   for(int i = 1;i <= n;i ++)
	   {
		 int k = 2*i-1;
	     for(int j= 1 ;j <= k; j ++ )
			 scanf("%1d",&a[i][j]);
	   }
		 if(ok1()||ok2()||ok3()||ok4()||ok5()||ok6())
			 ok = 1;
		 printf("Puzzle %d\n",t);
		 if(ok)
			 printf("Parts can be separated\n");
		 else printf("Parts cannot be separated\n");

	 }

return 0 ;
}
