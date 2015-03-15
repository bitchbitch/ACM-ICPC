#include<stdio.h>
int main()
{
   int n; 
   int a[100][100];
   scanf("%d",&n);
   int i ,j;
   for (i =1 ;  i<= n ; i ++)
	   for (j =1; j <= n ; j ++)
		scanf("%d",&a[i][j]);
    
   for (j =n ;  j >=1  ; j --)
   { for (i =1; i <= n ; i ++)
		printf("%d", a[i][j]);
     printf("\n");
   }
  return 0;
}
