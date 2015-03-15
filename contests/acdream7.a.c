#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int comp(const void *a ,const void *b)
{
   return *(int *)a - *(int *)b;
}
int a[100010],b[100010];
int main()
{  
    int n ,k;
	while (scanf("%d %d",&n,&k) != EOF)
	{
		int i ,j , m  ,l = 0 ,sum = 0  ;
	   for (i = 0 ; i < n ; i++)
		   scanf("%d",&a[i]);
       for (i = 0 ; i < n ; i++)
	   {
	        if (a[i]!= -1 )
			{
			  int t = 0,tp = i  ;
			  while (a[tp] != -1)
	        {	
		    	int s = tp;
		        
				tp = a[tp];
				a[s] = -1; 
				  t = t +1;
			}
			 b[l++] = t ;
			
			}
	  
	   }

      qsort(b,l,sizeof(int),comp);
	   for (i = 0 ; i <l ; i++)
		 if(k >= b[i]-1)
	      {
			  sum = sum +b[i];
		      k = k-b[i]+1; 
		  }
		 else 
		 {	sum = sum +k;
           break;
		 } 
	   printf("%d\n",sum);
	}
	return 0;
}
