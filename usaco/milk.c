/*
ID: dream.y1
PROG: milk
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
struct node 
{
  int x, y;
}a[6000];
int cmp(const void *a ,const void * b)
{
   return (*(node *)a).x - (*(node *)b).x;
}
int main(){
    FILE *fin = fopen("milk.in","r");
	FILE *fout = fopen("milk.out","w");
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n ,m; 
   fscanf(fin,"%d %d",&n,&m);
   for(int i = 1;i<= m;i ++)
   {
     fscanf(fin,"%d %d",&a[i].x,&a[i].y);
   }
   long long  sum = 0 ;
   int max = 0 ;
   qsort(a+1,m,sizeof(node),cmp);
   for(int i =1 ;i <= m;i ++)
   {
      if(max + a[i].y >= n)
	  {
	    sum += (n-max)*a[i].x;
		break;
	  }
	  else
	  {
	    sum += a[i].x * a[i].y;
		max += a[i].y;
	  }
   
   }
   
   fprintf(fout,"%lld\n",sum);
return 0 ;
}
