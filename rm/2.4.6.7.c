#include <stdio.h>
int main()
{
    
      int i=1,j=1,k;
      double sum;
      while(1.0/i >= 0.00001)
        {
             sum += 1.0/i*j;
              j=-j;
             i++;
         }
   printf("%lf\n",sum);
    
  return 0;
}
