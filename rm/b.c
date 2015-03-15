// File Name: b.c
// Author: darkdream
// Created Time: 2013年05月19日 星期日 21时35分49秒

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
  int n; 
  long long int  t[100];
  scanf("%I64d %I64d",&a,&b);
  scanf("%d",&n);
  for(int i =1 ; i <=n;i ++)
  {
     scanf("%I64d",&t[i]);
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
	  k = gcd(tempa,tempb);

	  tempa = tempa/k;
	  tempb =tempb/k;

  }
  if(tempa == a && tempb == b)
	  printf("YES\n");
  else
	  printf("NO\n");
return 0 ;

}
