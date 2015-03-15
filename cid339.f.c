#include <stdio.h>
#include <string.h>
char a[100010];
char b[30];
int l1;
int is(int i)
{  int j;
   if (i==1)
	   return 0;
   for ( j = i ; j < l1; j++)
	   if (a[j-i] != b[a[j]-'a'])
		   return 0;
   return 1;
}
int main()
{
   int n;
   scanf("%d",&n);
   getchar();
   while (n--)
   {  int j,k,n,s,i,t,l2;
      
	  gets(b);
	  gets(a);
      l1 = strlen(a);
      j = (l1+1)/2;
	   for ( ; j<l1; j++)
	      if (is(j))
			  break;
	   printf("%s",a);
	 for (i = strlen(a)-j ;i < j ; i++ )
	     printf("%c", (strchr(b,a[i]))-b+97);
	   
    printf("\n");

   }
   return 0;

}

