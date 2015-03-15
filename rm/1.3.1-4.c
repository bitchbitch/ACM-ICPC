#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    if (m-2*n>=0&& 3*n-m>=0&&m%2!=1)
     printf("%d %d",n-(m-2*n)/2,(m-2*n)/2);   
   else  printf("Wrong answer\n");
    return 0;
}
