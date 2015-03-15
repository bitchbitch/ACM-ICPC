#include <stdio.h>
#include <string.h>
int main()
{
   char a[1000];
   while (gets(a))
   {
      int i,j=0,q;
	 for (i = 0; i <strlen(a); i ++ )
         {
		    if (i == 0 && ((a[i] >='a' && a[i]<= 'z')||(a[i] <= 'Z'&& a[i] >= 'A')))
			   j = 1;
			else
             if (((a[i] >='a' &&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))&&!((a[i-1] >='a' && a[i-1] <='z')||(a[i-1] >= 'A' &&a[i-1] <= 'Z')))
		      j++;
		 }  

    printf("%d\n",j);

   }
 return 0;
}
