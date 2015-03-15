#include <stdio.h>
int main()
{
  int a[101][101]={0},k = 10000,i= 0 ,j = 0;
  while ( k>= 1)
  {
    while (j+1 <=100 && a[i][j+1] != 0) {a[i][++j] = k;k--;printf("1");}
	while (i+1 <=100 && a[i+1][j] != 0) {a[++i][j] = k;k--;printf("2");}
    while (j-1 >=1 && a[i][j-1] != 0) {a[i][--j] = k;k--;printf("3");}
    while (i-1 >=1 && a[i-1][j] != 0) {a[--i][j] = k;k--;printf("4");}
  }
  for (i = 1 ; i<= 100 ; i++)
	 {  for (j = 1 ; j<= 100 ;j ++)
          printf("%d ",a[i][j]);
		  printf("\n");
	 }
  return 0;
}


