// File Name: c.c
// Author: darkdream
// Created Time: 2013年04月12日 星期五 20时01分51秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
long long  int  a, p; 
long long  is(long long a, long long t)
{
   if(t == 1)
	   return a;
   else
   {
	  long long k = is(a,t/2);
	   if(t %2 == 0)
	   return k * k % p; 
	   
   else return (k *k)%p *a%p;
   }
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   while(scanf("%lld %lld",&a,&p) != EOF)
   {
		long long ans = 100000000000000000;
		a = a%p;
		int ok = 1;
	for(int i = 2; i <= sqrt(p); i ++) 
	  {
		if((p-1)%i== 0)
		{	
			
			if (is(a,i) == 1)
			{  
				//printf("%lld\n",is(a,i));
                if(i < ans)
					ans = i;
				ok = 0;
			}
		    if(is(a,(p-1)/i) ==1)
			{
				//printf("%lld\n",is(a,i));
                if((p-1)/i < ans)
					ans = (p-1)/i;
				ok = 0;
			}
		}
	  }
	 if(!ok)
	  printf("%lld\n",ans);
	 else
		 printf("%lld\n",p-1);
   }
return 0 ;
}
