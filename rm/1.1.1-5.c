#include <stdio.h>
#define PI 3.1415936
int main()
{
  double r,h;
  scanf("%lf %lf",&r,&h);
  printf("%.3lf\n",PI*r*r*2+h*r*PI*2);
  return 0;
}




