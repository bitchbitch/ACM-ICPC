// File Name: uva540.c
// Author: darkdream
// Created Time: 2013年05月16日 星期四 20时12分37秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int  p[1000001],s[1000001];
int find(int x)
{
    return p[x] == x?x:p[x] = find(p[x]);
}
int d[5004][5001];
int upd[5004];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
  int n,sc = 1;
  while(scanf("%d",&n) != EOF)
  {
	  memset(p,0,sizeof(p));
	  memset(s,0,sizeof(s));
	  memset(d,0,sizeof(d));
      memset(d,0,sizeof(d));
	  memset(upd,0,sizeof(upd));

      if(n==0)
		  break;
	  for(int i= 0;i <= 1000000; i ++ )
		  p[i] = i;
	  for(int i = 1;i <= n;i ++)
	  {
	     int k,temp,temp1;
		 scanf("%d",&k);
		 for(int j = 1 ;j <= k; j++)
		 {
		   
		   scanf("%d",&temp);
		   if(j >=2 )
	         p[temp]  = find(temp1);
		   temp1 = temp;
		 }
	  }//并查集
	  printf("Scenario #%d\n",sc);
	  sc++;
	int up = 0,low = 1 ,temp,lowd = 0 ;
	char str[100];
	while(1)
	{
	   
	   scanf("%s",str);
	   if(str[0] == 'E')
	   {
	      scanf("%d",&temp);
          if(s[find(temp)] != 0)
			  d[s[find(temp)]][upd[s[find(temp)]]++] = temp;
		  else
		  {	  
			  up++;
			  s[find(temp)] =	up;
		      d[up][upd[up]++] = temp;
		  }
	   }
	   else if(str[0] == 'D')
	   {
		   printf("%d\n",d[low][lowd]);
		   lowd++;
		   if(lowd == upd[low])
		   {  
			   s[find(d[low][0])] = 0 ;
			   lowd = 0;
		       low++;
		   }
	       
	   }
	   else
		  break;

	}
	printf("\n");
    /*for(int i = 1;i <= 3; i ++)
	{	for(int j = 1; j<= 3 ;j ++)
           printf("%d ",d[i][j]);
		printf("\n");
	}*/
  }
return 0 ;
}
