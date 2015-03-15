// File Name: b.c
// Author: darkdream
// Created Time: 2014年03月19日 星期三 23时47分56秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
double a, d;
int n ; 
long long k,p; 
double hehe(double t)
{
	//return t ; 
    p = t * 10000;
    double temp = p *1.0/ 10000;
	//printf("%lf**%lf\n",t,temp/10000);
	double temp1 = t - temp ; 
	if(0.0001 - (temp1 + 1e-11)> temp1)
		return temp;
    return temp + 0.0001;
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   scanf("%lf %lf %d",&a,&d,&n);
   double ans = 0 ; 
   for(int i= 1;i <= n;i ++)
   {
         ans = hehe(ans + d);
		  k = (long long )(ans/a) ;
		// printf("%d %d %lf\n",k,k%4,ans);
                    
		 if(k % 4 == 1 )
		 { printf("%lf %lf\n",hehe(a) ,hehe(ans - k * a) );
		 }
		 else if(k % 4 == 2 )
			 printf("%lf %lf\n",hehe(a -(ans - k* a ) ),hehe(a));
		 else if(k % 4 == 3 )
			 printf("%lf %lf\n",0.0,hehe(a - (ans - k *a )) );
		 else if(k % 4 == 0 )
			 printf("%lf %lf\n",hehe(ans - k *a ), 0.0);
   }
return 0 ;
}
