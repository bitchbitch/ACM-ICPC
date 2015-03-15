// File Name: k.c
// Author: darkdream
// Created Time: 2013年04月10日 星期三 17时02分33秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
struct bands
{
  int i ;
  int list[105];
};
struct bands band[15];
bool b[105];
int c[105],w[105];
int f[10005];
int main(){

  // freopen("/home/plac/problem/input.txt","r",stdin);
  // freopen("/home/plac/problem/output.txt","w",stdout);
  int n ,v ,k;
  while(scanf("%d %d %d",&n,&v,&k) != EOF)
  {
	  memset(band,0,sizeof(band));
	  memset(f,0,sizeof(f));
	  memset(b,0,sizeof(b));
     for(int i = 1;i <= n;i ++)
	 {   int m;
		 scanf("%d %d %d",&m,&c[i],&w[i]);
		 band[m].list[band[m].i] = i;
		 band[m].i++;
	 }
	 for(int i = 1;i <= k; i ++)
	 { int tempi;
	   for(int j = v ;j >= 0 ;j --)
	   { int max = INT_MIN; 
	     for(int t = 0 ; t < band[i].i; t++)
		 {
		    if(f[j-c[band[i].list[t]]] + w[band[i].list[t]] > max)
			{  
			   max = f[j-c[band[i].list[t]]] + w[band[i].list[t]];
			   tempi =  band[i].list[t];
			}
		 }
		 if(j == v)
			 b[tempi] = 1;
		 f[j] = max;
	   }
	 }
	 printf("%d\n",f[v]);
	// for(int i = 1;i <= n; i ++)
	//	 printf("%d ",b[i]);
	// printf("\n");
	 for(int i = 1; i <= n ; i++)
	 {
	     if(b[i]!= 1) 
		 { 
		    for(int j = v; j >= c[i]; j --  )
				f[j] = f[j] > (f[j-c[i]] + w[i]) ?f[j]:(f[j-c[i]]+w[i]); 
		 }
	 }
   printf("%d\n",f[v]); 
  }
return 0 ;
}
