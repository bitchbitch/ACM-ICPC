#include <stdio.h>
#include <string.h>
long long int a[]={0};
void sai()
{
   int i ;
   a[1] =1 ; 
   for (i =2 ;i <= 110; i++)
    {
	  if (a[i] == 0 )
	  {
	     int j  = i *i;
		 while (j <= 10000 )
		 {
		    a[j] = 1; 
			j = j +i ;
		 }
	  }
	}
}

int main()
{
      int i , sum = 0 ;
	   int t, b; 
	   int c[1230],c1[1230] ,j = 1; 
	   sai();
	  for (i =1 ; i<= 10000 ;i ++)
	    if (a[i] == 0 )
		   c[j++] = i;
       while (scanf("%d %d",&t,&b)!=EOF)
	   {
	      memset(c1,0,sizeof(c1));
		   int j , k ,l ,m;
		 for (i = 1; i <= 1229; )
		 {
		     if (t %c[i] ==0 )
			 { c1[i]++; t = t / c[i];}
			 else 
				 i++;
			
			
			 if (t == 0) break;

		 }
		 if (t != 0)
		 {
		  for ()
		 
		   break;
		 }
		 for (i = 1 ; i <= 1229;i++)
			if (c1[i] != 0)
				printf("%d ",c[i]);
	
	   
	   }
  return 0 ;
}
