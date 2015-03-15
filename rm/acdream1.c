#include <stdio.h>
#include <string.h>
int main()
{
   char a[1120];
    int n,i,j,k;
   while (~scanf("%d",&n))
   {   j=0;
      getchar();
      scanf("%s",a);
     
      k=strlen(a);
     for (i=0;i<k;i++)
       if (a[i]=='L')
             j++;
     printf("%d %d\n",j+n-k,j);
      
   }

 return 0;

}
