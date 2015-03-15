#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
   int t;
   scanf("%d",&t);
   while (t --)
   {
     int n ,i , j , k,a[1002] ={0},b[2002] = {0} , l = 0,ti = 0;
	 scanf("%d %d",&n,&k);
	
	 for (i = 1 ;i <=  n ;i ++)
	   	 scanf("%d",&a[i]);
	 
	 for (i = 1 ;i <= n   ; i ++)
		 for (j = i+1 ; j<= n ; j ++)
		  	 b[abs(a[j]-a[i])]  = 1 ;
    
	 for (i = 0 ,l = 0  ; l < k  && i <= 2000; i ++)
	    {
		
			
			if (b[i])
		    {  
			    l++;
			   ti = i;
			
		    }
		   
		}	 
	printf("%d\n",ti);
	
   }

 return 0 ;

}

