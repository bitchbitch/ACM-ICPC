// File Name: b.c
// Author: darkdream
// Created Time: 2013年12月13日 星期五 22时12分44秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
long long w,m,k;
long long q[100];
long long  l[20];
int main(){
  q[0] = 0; 
  q[1] = 10 ; 
  l[1] = 1;
  for(int i = 2;i <= 20;i ++)
  {  q[i] = q[i-1] *10;
     l[i] = l[i-1] +1;
  }
  //printf("%lld",q[20]);
  scanf("%lld %lld %lld",&w,&m,&k);
  long long ans = 0 ; 
  for(int i =1 ;i <= 20;i ++)
  {
       if( m < q[i] && m >= q[i-1])
	   {
	      if(w/(k*l[i]) > q[i] - m)
		  {
		      ans += q[i] - m;
			  w =  w - (k*l[i])*(q[i] - m);
			  m = q[i];
		  }else{
		      ans += w/(k*l[i]);
			  break;
		  }
	   }

  }
  printf("%lld\n",ans);
return 0 ;
}
