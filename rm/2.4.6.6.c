#include <stdio.h>
int main()
{
        long long m,n,i;

    while (scanf("%lld %lld",&n,&m) != EOF)
   {

       double sum = 0;
      for (i = n; i <= m ; i++)
           sum +=1.0/(i*i*1.0);
     printf("%.5lf\n",sum);

   } 

   return 0;
}
