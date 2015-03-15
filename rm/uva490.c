#include <stdio.h>
#include <string.h>
int main()
{
   char a[120][120]={0};
   int i = 1,max = 0, j ,k ;
   while (gets(a[i++]))
   {
	 if (strlen(a[i-1]) > max)
		 max = strlen(a[i-1]);
      
   }
   for(j = 0 ; j < max; j++)
   {
     for (k = i-2; k >= 1 ; k -- )
	   	if (a[k][j]=='\0')
			printf(" ");
	   else 
		 printf("%c",a[k][j]);
	 printf("\n");
   }
  return 0;
}
