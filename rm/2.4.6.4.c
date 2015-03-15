#include <stdio.h>
int main()
{
     int n;
    while (scanf("%d",&n) != EOF)
    {
        int i,j,k;
        for (i = 1 ; i <= n ; i++)
          {
              for (j = 1 ; j <= i-1; j++)
                printf(" ");
              for (j = 1 ; j <= 2*(n-i+1)-1 ; j++ )
                printf("*");
              printf("\n");  


          }
     }
    return 0;

}
