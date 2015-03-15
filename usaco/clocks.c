/*
ID: dream.y1
PROG: clocks
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
FILE *fin = fopen("clocks.in","r");
FILE *fout = fopen("clocks.out","w");
int map[10] = {0};
int times[10] = {0,4,3,4,3,5,3,4,3,4};
int visit[4][4][4][4][4][4][4][4][4] ={0};
int trys[10][6] = {{0},{0,1,2,4,5},{0,1,2,3},{0,2,3,5,6},{0,1,4,7},{0,2,4,5,6,8},{0,3,6,9},{0,4,5,7,8},{0,7,8,9},{0,5,6,8,9}};
int ans[1000];
void print()
{
  for(int i =1 ;i<= 9 ;i ++)
	  printf("%d ",map[i]);
  printf("\n");
  return ;
}
void change(int k , int T)
{
  if(T == 1 )
  {
    for(int i = 1;i <= times[k];i ++)
	{
	  map[trys[k][i]]  = (map[trys[k][i]] +1)%4;
	}
  }
  else
  {
     for(int i =1; i <= times[k];i ++)
	 {
	   if(map[trys[k][i]] == 0 )
		   map[trys[k][i]] = 3; 
	   else
		   map[trys[k][i]] -= 1;
	 }
  }
}
int cmp(const void *a ,const void *b)
{
    return *(int *)a - *(int *)b;
}
int ok = 0 ;
void dfs(int step, int limit,int k)
{

   if(step == limit)
	{
	   for(int i = 1;i <= 9 ;i ++)
		   if(map[i] != 0)
			   return ;
	   ok = 1;
	   //qsort(ans,step,sizeof(int),cmp);
	   for(int i =0 ;i <= step-1 ;i ++)
		   printf(i == 0?"%d":" %d",ans[i]);
	   printf("\n");
	   return ;
	}
   if(ok)
		return ;

	for(int i = 1 ;i <= 9 ;i ++)
	{
	   
	    change(i,1);
		if(visit[map[1]][map[2]][map[3]][map[4]][map[5]][map[6]][map[7]][map[8]][map[9]] == 0)
	    {
	      visit[map[1]][map[2]][map[3]][map[4]][map[5]][map[6]][map[7]][map[8]][map[9]] = 1;
		  ans[step] = i;
		  dfs(step+1,limit,i);
		}
		change(i,-1);
	}
	return ;
}
int main(){


   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   
   for(int i =1 ;i<= 9;i ++)
   {
	  int temp ;
      scanf("%d",&temp);
      map[i] = (temp/3) % 4;
   }
   for(int i = 1 ;  ;i ++)
   {
	 memset(visit,0,sizeof(visit));
	 visit[map[1]][map[2]][map[3]][map[4]][map[5]][map[6]][map[7]][map[8]][map[9]] = 1;
	 dfs(0,i,1);
     if(ok)
	   break;
	// printf("%d\n",i);
   }
return 0 ;
}
