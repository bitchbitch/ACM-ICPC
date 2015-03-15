#include <stdio.h>
#include <string.h>
int main()
{   char a[200];
	while (gets(a))
	{
	  int i, ts = 0, j , l;
	   if(a[0]=='\n')
		   printf("\n");
	   else 
	   {  ts = a[0] - 48;
		   for (i = 1 ; i < strlen(a) ; i++ )
		   {
			 if(a[i] == '!' )
				 printf("\n");
			 else  if (a[i]>= '0' && a[i] <= '9')
			 { if (a[i-1] <= '9' && a[i-1] >= '0' )
					 ts = ts +a[i] - 48;
			   else ts = a[i] - 48;
			 }      
			 else 
				 for(j = 1 ; j <= ts ; j ++)
					if (a[i] == 'b')
						printf(" ");
			       else 
					 printf("%c",a[i]);


		   }
		printf("\n");

	   }
	}
	
  return 0;
}
