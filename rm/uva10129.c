// File Name: uva10129.c
// Author: darkdream
// Created Time: 2013年06月16日 星期日 22时42分07秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int map[100][100];
int in[100];
int out[100];
int visit[100];
void dfs(int k )
{
   for(int i = 1; i <= 30 ;i ++)
   {
     if(map[k][i] != 0 && visit[i] == 0)
	 {
	   visit[i] =1;
	   dfs(i);
	 }
   }
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int t;
   scanf("%d",&t);
   while(t--)
   { 
	   memset(map,0,sizeof(map));
	   memset(in,0,sizeof(in));
	   memset(out,0,sizeof(out));
	   memset(visit,0,sizeof(visit));
	   int n ,a, b;
	   char str[1005];
	   scanf("%d",&n);
	   while(n--)
	   {
	     scanf("%s",str);
		 a = str[0] - 'a' + 1;
		 b = str[strlen(str)-1] - 'a' + 1;
		 map[a][b] ++;
		 in[b] ++;
		 out[a] ++;
	   }

	   int sumin =0;
	   int sumout = 0;
	   int begin = a, ok = 1;
	   for(int i =1;i <= 30; i ++)
        {
		  if( in[i] - out[i] == 1)
			  sumin++;
		  else  if(out[i] - in[i] == 1)
		  { 
			  sumout++;
		      begin = i ;
		  }
		  else if(in[i] != out[i]){ok = 0 ;
		    //printf("****\n");
		  }
		}
	    visit[begin] = 1;
	    dfs(begin);
       for(int i = 1; i <= 30 ;i ++)
	   {
	       if(in[i] || out[i])
			   if(visit[i] == 0)
			   {   ok = 0;
			  //    printf("****\n");
			   }
	   }
	   if(((sumin == 0 && sumout == 0) || (sumin == 1 && sumout == 1) ) && ok)
		   printf("Ordering is possible.\n");
	   else
		   printf("The door cannot be opened.\n");
       
   
   }
return 0 ;
}
