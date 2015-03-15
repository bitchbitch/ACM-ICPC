#include <stdio.h>
#include <math.h>
int main()
{
  double n;
  scanf("%lf",&n);
  if (n<=0)
  n=-n;
  printf("%lf\n",floor(n));
  return 0;

}
