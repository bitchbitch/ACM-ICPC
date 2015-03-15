/*
ID: dream.y1
PROG: barn1
LANG: C++
*/ 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int cmp(const void *a ,const void * b)
{
  return *(int *)b - *(int *)a;
}
int cmp1(const void *a ,const void *b )
{
     return *(int *)a - *(int *)b;
}
int hash[1000] = {0};
int main(){
    FILE *fin = fopen("barn1.in","r");
	FILE *fout = fopen("barn1.out","w");
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
    int m ,s ,c;
	fscanf(fin,"%d %d %d",&m,&s,&c);
    int ans[1000] = {0};
	int t = 0 ;
	int now,temp;
	int star = 0 ; 
	int a[1000];
	for(int i =1 ;i<= c ;i ++)
	{
		fscanf(fin,"%d",&a[i]);
	}
    qsort(a+1,c,sizeof(int),cmp1);
    
	for(int i= 2; i <= c ;i ++)
	{
	   if(a[i] -a[i-1] != 1)
	   {
	     t++;
		 ans[t] = a[i]-a[i-1] -1;
	   }
	}
	qsort(ans+1,t,sizeof(int),cmp);
	int sum = a[c] - a[1] + 1 ;
	for(int i =1 ;i<= m-1 ;i ++)
		sum -= ans[i];
	fprintf(fout,"%d\n",sum);
return 0 ;
}
