// File Name: b.c
// Author: darkdream
// Created Time: 2013年12月13日 星期五 22时12分44秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
__int64 w,m,k;
__int64 q[100];
__int64  l[20];
int main(){
  q[0] = 0;
  q[1] = 10 ;
  l[1] = 1;
  for(int i = 2;i <= 20;i ++)
  {  q[i] = q[i-1] *10;
     l[i] = l[i-1] +1;
  }
  //printf("%I64d",q[20]);
  scanf("%I64d %I64d %I64d",&w,&m,&k);
  __int64 ans = 0 ;
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
  printf("%I64d\n",ans);
return 0 ;
}
