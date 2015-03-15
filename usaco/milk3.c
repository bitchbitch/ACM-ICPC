/*
ID: dream.y1
PROG: milk3
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
FILE *fin = fopen("milk3.in","r");
FILE *fout = fopen("milk3.out","w");
int a[4] = {0};
int b[4] = {0};
int visit[30][30][30];
int t = 0 ;
int ans[100] = {0};
int cmp(const void *a ,const void *b)
{
   return *(int *)a - *(int *)b;
}
void change(int i, int j)
{
    if(b[i] + b[j] > a[j])
	{

	    b[i] = b[i]- (a[j] -b[j] );
		b[j] = a[j];
	}
	else
	{
		b[j] = b[i]+b[j];
	    b[i] = 0 ; 
	}
}
void dfs()
{
   if(b[1] == 0 )
   {
     t ++;
	 ans[t] = b[3];
   }
   int temp[4];
   //fprintf(fout,"%d %d %d\n",b[1],b[2],b[3]);
   for(int i = 1;i<= 3;i ++)
   {
      for(int j = 1; j<= 3; j ++)
	  {
	    if(i != j)
		{
			memcpy(temp,b,sizeof(b));
		    change(i,j);
		    if(visit[b[1]][b[2]][b[3]] == 0 )
			{
			  visit[b[1]][b[2]][b[3]] =1 ;
			  dfs();
			}
			memcpy(b,temp,sizeof(b));
		}
	  }
   }
  return ; 
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   
  fscanf(fin,"%d %d %d",&a[1],&a[2],&a[3]);
  b[3] = a[3];
  visit[0][0][b[3]] = 1;
  dfs();
  qsort(ans+1,t,sizeof(int),cmp);
  for(int i = 1; i <= t;i ++)
	  fprintf(fout,i == 1?"%d":" %d",ans[i]);
  fprintf(fout,"\n");
  return 0 ;
}
