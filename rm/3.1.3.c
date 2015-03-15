#include <stdio.h>
#include <string.h>
int a[100][100] = {0};
int main()
{
  int n;
  while (scanf("%d",&n) != EOF)
  {
    int k = 1;
	int i,j;
    memset(a,0,sizeof(a));
	a[1][n] = 1;
    i=1;j = n;
	k = 1;
	while(k!=n*n)
	{
	  while (i+1 <= n && a[i+1][j] == 0) {a[i+1][j] = ++k; i = i+1;}
	  while (j-1 >= 1 && a[i][j-1] == 0) {a[i][j-1] = ++k; j = j-1;}
	  while (i-1 >= 1 && a[i-1][j] == 0) {a[i-1][j] = ++k; i = i-1;}
	  while (j+1 <= n && a[i][j+1] == 0) {a[i][j+1] = ++k; j = j+1;}	
    }
  for (i = 1 ; i <= n ; i ++)
  {
      for  (j = 1; j <= n; j ++)
		   printf("%4d",a[i][j]);
	  printf("\n");
  }
  
  
  }
  return 0;
}


