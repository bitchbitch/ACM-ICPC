/*
ID: dream.y1
PROG: crypt1
LANG: C++
*/ 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int hash[20] = {0};
int hasha[1000000] = {0};
int num[6];
int sum = 0 ;
int a[20],n;
int isnum(int k)
{

   while(k >= 10 )
   {
      if(hash[(k%10)] == 0)
	  {   
		  return 0 ;
	  }
	  k = k / 10;
   }
   if(hash[k] == 0 )
	   return 0 ;
   return 1;
}
void dfs(int t)
{
  if (t == 6)
  {
    int k1 = num[3] + num[2] *10 + num[1] * 100;
	int k2 = num[4] * k1;
	int k3 = num[5]*k1;
	int k4 = k3*10 + k2;
	//fprintf(fout,"%d %d %d\n",k2,k3,k4);
	if(k2 <1000 && k3 < 1000 & k4 < 10000)   
	   if( isnum(k2) && isnum(k3) && isnum(k4))
	   {
	     sum ++;
	   }
   return ;
  }
  for(int i =1; i <= n; i ++)
  {
    num[t] = a[i];
	dfs(t+1);
  }
}
int main(){
    FILE *fin = fopen("crypt1.in","r");
	FILE *fout = fopen("crypt1.out","w");
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   fscanf(fin,"%d",&n);
   for(int i  = 1; i <= n;i ++)
   {  
	   fscanf(fin,"%d",&a[i]);
       hash[a[i]]  = 1;
   }
   dfs(1);
   fprintf(fout,"%d\n",sum);
return 0 ;
}
