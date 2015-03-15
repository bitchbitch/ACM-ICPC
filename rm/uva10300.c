#include <stdio.h>
int main()
{
   int t ;
   scanf("%d",&t);
   while (t--)
   {
     int n , a,b,c,sum = 0;
	 scanf("%d",&n);
	 while (n--)
	 {
	   scanf("%d %d %d",&a,&b,&c);
	     sum += a*c;

	   
	 }
	 printf("%d\n",sum);
   }
  return 0;
}
