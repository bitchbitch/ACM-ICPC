#include <stdio.h>
#include <string.h>

int main()
{  
	char a[100] , sum=0, i = 0  ;
    while (scanf("%s",a) != EOF)
    {
	    
		i ++;
		sum = sum + strlen(a);
	
	}
	printf("%lf",sum*1.0/i);

   return 0;

}
