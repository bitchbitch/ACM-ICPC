/*
ID: dream.y1
PROG: dualpal
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int a[200];
int is(int n )
{
  for(int i = 1; i<= n/2+1;i ++)
  {
     if(a[i] != a[n-i +1])
		 return 0 ;
  }
  return 1;
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   FILE *fin = fopen("dualpal.in","r");
   FILE *fout = fopen("dualpal.out","w");
   int n,m;
   fscanf(fin,"%d %d",&n, &m);
   int k = 0 ;
   while(k < n)
   {
      m ++ ;
	  int sum =  0;
	  for(int i = 2; i<= 10; i ++)
	  {
		memset(a,0,sizeof(a));
		int temp = m ;
		int t = 0 ;
	    while( temp >= i)
		{
		  t++;
		  a[t] = temp %i ;
		  temp = temp / i;
		}
	   t++;
	   a[t] = temp;
	   if(is(t))
		   sum ++;
	    if(sum == 2)
	    {
		   fprintf(fout,"%d\n",m);
		   k++;
		   break;
	    }
	  }
	  
   }
return 0 ;
}
