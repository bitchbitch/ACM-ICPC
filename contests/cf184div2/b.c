#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
long long int gcd(long long int a, long long int b)
{
      return b == 0?a:gcd(b,a%b);
}

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
  long long int  a, b; 
  long long int c,d;
  int n; 
  double  t[100];
  scanf("%lf %lf",&a,&b);
  scanf("%d",&n);
  for(int i =1 ; i <=n;i ++)
  {
     scanf("%lf",&t[i]);
  }
  long long int  tempa,tempb,temp;
  tempa = t[n];
  tempb = 1;
  long long int  k = gcd(a,b);
  a = a/k;
  b = b/k;
  for(int i = n-1 ;i >= 1;i --)
  {
      temp = tempa;
      tempa = t[i]*tempa + tempb;
      tempb = temp;
      c = tempa ;
	  d = tempb;
      tempa = tempa/k;
      tempb =tempb/k;
  }

  c = tempa;
  d = tempb;
  if(c == a && d == b)
      printf("YES\n");
  else
      printf("NO\n");
return 0 ;

}
