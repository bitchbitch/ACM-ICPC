#include <stdio.h>
int main()
{
    int a,b,c;
   while(scanf("%d %d %d",&a,&b,&c) != EOF)
  {  double k;
     int i,j;
     printf("%d.",a/b);
    
     k = a*1.0/b-a/b;
    for(i=1;i<=c;i++)
    {
        
      if (i==c) 
         printf("%d",(int)((k+0.05)*10));
      else 
         printf("%d",(int)(k*10));

        k = k*10;
       k = k- (int) k;
    }
  }
 return 0;


}
