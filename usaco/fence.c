/*
ID: dream.y1
PROG: fence
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int hs[2000];
int map[600][600];
int n;  
   int be = 0; 
   int en = 0;
int ans[1000];
int numans = 0 ; 
int okk = 0 ;
int is  = 0 ; 
void dfs(int k  )
{
   if(!hs[k])
   {
      ans[numans] = k ; 
	  numans = numans +1;
   }else {
       while(hs[k])
	   {
	      for(int i = 1;i <= 500;i++)
		  {
		       if(map[k][i])
			   {
			       map[k][i] -- ; 
				   map[i][k] -- ; 
				   hs[i] --; 
				   hs[k] --;
				   dfs(i);
			   }
		  }
	   }
     ans[numans] = k ; 
	 numans ++ ; 
   
   }
	   

}
int main(){

   freopen("fence.in","r",stdin);
   freopen("fence.out","w",stdout);
   memset(map,0,sizeof(map));
   memset(hs,0,sizeof(hs));
   scanf("%d",&n);
   for(int i = 1;i  <= n;i ++)
   {
     int a, b; 
	 scanf("%d %d",&a,&b);
	 map[a][b] ++ ; 
	 map[b][a] ++ ; 
	 hs[a] ++ ; 
	 hs[b] ++ ; 
   }
   int ok = 0 ;
   int bbe = INT_MAX ; 
   for(int i = 1;i <= 500;i ++)
   {
      if(hs[i] % 2== 1)
		{
			  is = 1; 
		    
			  be = i ; 
              ok = 1;
			  break;
		}
	  else if(hs[i])
	  {
	    bbe = bbe > i ? i:bbe; 
	  }
   }
   if(ok ) dfs(be);
   if(!ok) 
	   dfs(bbe);
   for(int i = numans -1 ;i  >= 0 ; i --)
	   printf("%d\n",ans[i]);
return 0 ;
}
