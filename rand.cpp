#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 1000000

int main(){
   freopen("input.txt","w",stdout);
   srand( (unsigned)time( NULL ));
  /*for(int i =1 ;i<= MAX;i ++)
     {
       printf("%d %d\n",Rand(8,99999999)+1,Rand(8,99999999)+1);
     }
     //printf("%d\n",Rand(9));
  */
  for(int i= 0 ;i <= 50;i ++)
	for(int j = 0 ;j <= 99; j ++)
		printf("%d.%d\n",i,j);
  return 0;
}
