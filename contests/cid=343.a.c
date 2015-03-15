#include <stdio.h>
int main()
{
  long long int t ;
  scanf("%lld",&t);
  while (t--)
  {  long long int m;
	   scanf("%lld",&m);
	   printf("%lld\n",(m*m)%10000);
  }
  
  return 0;
}
