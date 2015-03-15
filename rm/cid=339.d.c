#include<stdio.h>
#include<math.h>
int main()
{   int  t;
   __int64  n;
  scanf("%d",&t);
   while(t --)
   { 
	
     scanf("%I64d",&n);
	 printf("%d\n",(int)pow(10,n*log10(n)-floor(n*log10(n))));
   
   }
   return 0;
}
