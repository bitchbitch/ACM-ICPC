#include <stdio.h>
int main()
{
    int n;
   scanf("%d",&n);
   if (n*95>=300)
    printf("%.2lf\n",n*95*0.75);
  else printf("%d\n",n*95);
  return 0;
}
