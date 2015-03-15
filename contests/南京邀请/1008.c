#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  int a[10000];
  int n; 
  while(scanf("%d",&n) != EOF)
   {
    int temp ;
    memset(a,0,sizeof(a)); 
    int k ;      
 for(int i = 1;i<= n +1;i ++)
      {  scanf("%d",&temp);
          a[temp]++;
          if(a[temp] == 2)
             k = temp ; 
        }
    printf("%d\n",k);
  }
return 0 ; 
}
