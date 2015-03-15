#include <stdio.h>
int main()
{
   int n ,m;
   while (scanf("%d %d", &n,&m) != EOF)
   {
       int a[600][600]={0};
	    int i , j , k , l ,t ,sum = 0;
		for (i = 1; i <= n ; i ++)
		{	scanf("%d",&t);
            for (j = 1; j <= t ; j++)
		       {
			     scanf("%d",&l);
					 a[i][l] = 1;
			   }
		}
      
     for(i = 1 ; i <= n ; i++)
	 { for (j = 1 ; j <= m ; j ++)
		  printf("%d ",a[i][j]);
       printf("\n");
	 }


   }
   return 0;
}
