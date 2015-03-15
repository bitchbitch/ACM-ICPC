#include <stdio.h>
int main()
{
    int n,i;
    while (scanf("%d",&n)!=EOF)
      { i=0;
         while (n!=0)
         {
            i=i+1;
            n=n/10;           
 
          }
         printf("%d\n",i);
     } 
    return 0;
}
