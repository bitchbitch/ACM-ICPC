// File Name: findyourmin.c
// Author: darkdream
// Created Time: 2013年01月26日 星期六 16时28分57秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int  h[200010];
long long int d[200010];
int main(){
	FILE *p1 = fopen("output.txt","w");
	long long j , n , k, a, b, c, r, t , z, i;
	scanf("%lld",&t);
  for (z =1 ; z <= t ; z++)
  {	 
  memset(h,0,sizeof(h));
  memset(d,0,sizeof(d));
   scanf("%lld %lld %lld %lld %lld %lld",&n, &k , &a , &b ,&c,&r);
   
   d[1] = a ;
   if (a <= k*2)
   h[a] = 1;
   for (i =2 ; i <= k ; i++)
   {   d[i] =( b%r*d[i-1]%r +c%r)%r;
	   if (d[i] <= k+1) 
	      h[d[i]] ++;
   }


   for (i = 1; i <=  k +1   ; i++)
   {
        for(j = 0; ; j++)
			if(h[j] == 0)
				break;
      if (d[i] <= k+2)
	     h[d[i]] -- ;
		 d[i] = j ;
		 h[j] ++;
	   
   }
   if ((n - k)%(k+1) == 0 )
	   n = k+1;
    else
		n = (n-k)%(k+1);
   fprintf(p1,"Case #%lld: %lld\n",z,d[n]);

  }

  fclose(p1);		
		
return 0 ;
}
