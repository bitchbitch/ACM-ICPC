#include <stdio.h>
int main()
{
  int n ;
  while (scanf("%d",&n),n )
  {
      getchar();
	  int  i, a[100]={0},max = 0;
	    char c[30];
	  for (i = 1 ; i<= n ; i++)
	  {  gets(c);
	     int j;
		 for( j = 1 ; j<= 24; j ++)
              if(c[j] == 'X')
				  a[i]++;
		 if (a[i] > max )
			 max = a[i];
	  }
	  int sum = 0 ;
	for ( i = 1 ; i <= n; i ++)
		sum += max - a[i];

  printf("%d\n",sum);
  }
  return 0;
}

