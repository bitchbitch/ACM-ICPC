#include <stdio.h>
#include <string.h>
#include <math.h>
long long extgcd(long long a, long long b, long long &x, long long &y)
{
    long long d, t;
    if (b == 0) { x = 1; y = 0; return a; }
    d = extgcd(b, a % b, x, y);
    t = x - a/b*y; x = y; y = t;
    return d;
}
int main()
{
//    freopen("/home/plac/problem/input.txt","r",stdin);
  //  freopen("/home/plac/problem/output.txt","w",stdout);

     long long x,y,c;
     while(scanf("%lld %lld %lld",&x,&y ,&c) != EOF)
     {
         long long X,Y;
         long long d = extgcd(x,y,X,Y);
         if(c %d )
         {
           printf("sorry\n");
         }else{
          long long r = y/d;
		  if(r <= 0 )
			  r = -r;
		  long long  k = ((c*X%r + r)% r);
		  long long  fuck =(c- k*x)/y;
          printf("%lld %lld\n",k,fuck);
         }
     
     }
    
     return 0; 
}
