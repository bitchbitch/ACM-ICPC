#include <stdio.h>
int main()
{
    int n;
    for (n = 100 ; n <= 999 ;n++)
    {
          int a,b,c;
          a = n%10;
          b = n/10%10;
          c = n/100;
          if (a*a*a+b*b*b+c*c*c == n)
              printf("%d\n",n);

   }
 return 0;



}
