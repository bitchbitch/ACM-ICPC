#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{ 
	char a[100],c[100]={0};
  int i , j , k ,l ;
  long  sum = 1 ;
  char *t;
  gets(a);
  for (i = 0 ; i < strlen(a) ; i ++)
        if (!(a[i] <= '9' && a[i] >= '0'))
			a[i] = ' ';
  t = a ; 
 while(sscanf(t,"%d",&k) != EOF && t < a + strlen(a)) 
 { memset(c,0,sizeof(c)); 
   snprintf(c,100,"%d",k);
   sum = sum *k %1000;
   printf("%d\n",sum);
   t = strstr(t,c) + strlen(c);
 }
  
  return 0;
}
