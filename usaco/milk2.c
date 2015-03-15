/*
ID: dream.y1
PROG: milk2
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int n; 
struct node
{
  int x, y ;
}list[6000];
int cmp(const void *a ,const void *b)
{
    if((*(node *)a).x == (*(node *)b).x)
		return (*(node *)a).y - (*(node *)b).y;
	else
		return (*(node *)a).x - (*(node *)b).x;
}
int maxa = 0;
int maxb = 0;
int main(){
     FILE *fin  = fopen ("milk2.in", "r");
	 FILE *fout = fopen ("milk2.out", "w");
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   fscanf(fin,"%d",&n);
   for(int i =1; i<= n;i ++)
   {
     fscanf(fin,"%d %d",&list[i].x,&list[i].y);
   }
   qsort(list+1,n,sizeof(node),cmp);
   int kmax = list[1].x;
   int wmax = list[1].y;
   maxa = list[1].y - list[1].x;
   for(int i = 2;i <= n;i ++)
   {

      if(list[i].x > wmax) 
	  {
	     if(wmax - kmax > maxa)
	       maxa  = wmax - kmax;
		 if(list[i].x - wmax > maxb)
			 maxb = list[i].x - wmax;
         kmax = list[i].x;
		 wmax = list[i].y;
	  }
	  else
	  {
	     if(list[i].y > wmax)
			 wmax = list[i].y;
	  }

   
   }
   if(wmax - kmax >maxa)
	 maxa = wmax - kmax; 
   fprintf(fout,"%d %d\n",maxa,maxb);
return 0 ;
}
