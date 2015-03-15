// File Name: b.c
// Author: darkdream
// Created Time: 2013年08月16日 星期五 23时50分45秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
long long a, b  , c, d,tc,td;
long long gcd(long long i , long long j )
{
   return j== 0? i :gcd(j,i%j);
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
	scanf("%I64d %I64d %I64d %I64d",&a,&b,&c,&d);
    double k1,k2 ;
	k1 = a*1.0/b;
	k2 = c*1.0/d;
    if(k1 > k2)
	{
	    long long t1,t2;
		t1 = d/gcd(b,d);
		t2 = b/gcd(b,d);
		a =  a* t1;
		b =  b* t1;
		c = c * t2;
		d = d * t2;
        long long k = a*b - d *c;
		printf("%I64d/%I64d",k/gcd(a*b,k),a*b/gcd(a*b,k));
	
	}else {
	    long long t1,t2;
		t1 = c/gcd(a,c);
		t2 = a/gcd(a,c);
		a =  a* t1;
		b =  b* t1;
		c =  c* t2;
		d =  d* t2;
        long long k = a*b - d *c;
		printf("%I64d/%I64d",k/gcd(a*b,k),a*b/gcd(a*b,k));
	}
return 0 ;
}
