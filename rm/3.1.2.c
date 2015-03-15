#include <stdio.h>
int main()
{
     int a[10000]={0};
	 int n,k,i,j;
     while (scanf("%d %d",&n,&k) != EOF)
	 {
	    for (i = 1; i <=k ; i++)
		  for (j = 1; j <= n ; j ++)
			 if (j%i == 0 )
				a[j]=!a[j];
	    for (i = 1 ; i <= n ; i++)
			 if (a[i] == 1)
				 printf("%d ",i );
      }
      

  return 0;

}
