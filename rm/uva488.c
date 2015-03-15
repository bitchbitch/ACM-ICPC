#include <stdio.h>
int main()
{
  int n ,i;
  scanf("%d",&n);
  for ( i = 1 ; i <= n ; i++) 
  {
	int a, b , j , k, e, f, l;
	scanf("%d %d",&a,&b);
	for (j = 1 ;j <=b ;j++ )
	 {
	    if (i != 1 || j != 1)
			printf("\n");
		 for (k = 1 ; k <= a; k++)
		{	for (l = 1; l <= k; l++ )
			  printf("%d",k);
          printf("\n");
		} 
        for (k = a - 1; k >=1 ; k--)
		{
		  for (l = 1 ; l <= k; l++)
			  printf("%d",k);
		  printf("\n");
		}
	 }

  }
  return 0; 
}
