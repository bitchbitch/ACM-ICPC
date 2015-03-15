/*
ID: dream.y1
PROG: palsquare
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
FILE *fin = fopen("palsquare.in","r");
FILE *fout = fopen("palsquare.out","w");
int a[100];
int is(int n)
{
  for(int i =1 ;i <= n;i ++)
      if(a[i] != a[n-i+1])
		  return 0 ;
  return 1;
}
void print(int n )
{

  for(int i =1 ;i<= n;i ++)
	  if(a[i] < 10 )
		  fprintf(fout,"%d",a[i]);
	  else 
		  fprintf(fout,"%c",a[i]-10 +'A');
  fprintf(fout,"\n");
}
int main(){
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int b;
   fscanf(fin,"%d",&b);
   for(int i = 1;i <= 300;i ++)
   {
     int temp = i*i ;
	 int t = 0 ; 
	 while(temp >= b )
	 {
	    t ++;
		a[t] = temp % b; 
		temp = temp /b;
	 }
	 t ++ ; 
	 a[t] = temp;
	 if(is(t))
	 {
	   int d[100];
	   int k = i ; 
	   int kx = 0 ; 
	   while(k >= b)
	   {
	     kx ++;
		 d[kx] = k%b;
		 k = k /b;
	   }
	   kx ++;
	   d[kx] = k;
       for(int j = kx ;j >= 1; j --)
		   if(d[j] < 10 )
			   fprintf(fout,"%d",d[j]);
			else fprintf(fout,"%c",d[j] - 10 + 'A');
	   fprintf(fout," ");
	   print(t);
	 }
   }
return 0 ;
}
