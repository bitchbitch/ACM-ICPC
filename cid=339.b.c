#include <stdio.h>
int main()
{
   int t ;
   __int64 n,b;
    scanf("%d",&t);
   while (t--)
   { int i;
     scanf("%I64d %I64d",&n,&b);
	 for (i = 0; i<= 9973 ; i++)
           if((b%9973*i%9973)%9973 == n)
			   printf("%d\n",i);
	 
   }
   return 0;
}
