// File Name: 4704.c
// Author: darkdream
// Created Time: 2013年09月08日 星期日 20时32分42秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long
#define maxn 100009
#define mod 1000000007
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);


char str[maxn];
LL a[maxn];
LL POW (LL n ,LL k )
{
   LL ans = 1;
   LL p = n;
   while(k)
   {
       if(k &1)
		   ans =(ans * p)%mod ;
	   p = p*p %mod;
	   k >>=1;
   }
   return ans;
}
LL len ;
LL chu(LL k){
   LL temp = 0;
   for(int i = len;i >=1 ;i --)
   {
      temp = temp*10 + a[i];
	  if(temp > k )
		temp = temp%k;
   }
 return temp;
}
void jian()
{
  for(int i = 1;i <= len ;i ++)
  {
     if(a[i] >= 1)
	 {
	  a[i] -= 1;
	   return;
	 }
	 else 
		 a[i] = 9;
  }
}
int main(){
    while(scanf("%s",&str[1]) != EOF)
	{
	   len = strlen(&str[1]);
	  for(int i = 1; i<= len ;i ++)
		  a[i] = str[len-i+1] - '0';
       jian();	
       LL k = chu(mod-1);
	   printf("%lld\n",POW(2,k));
	}

return 0 ;
}
