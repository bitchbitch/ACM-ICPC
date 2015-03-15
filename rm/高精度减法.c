#include <stdio.h>
int main()
{
   int a[100],i=1,j,k,l,m,n,x,y,z,w,w1,w2;
   while (scanf("%1d",&a[i]) != EOF)
   {
	   i = i+1;
   }

   i -= 1;

   for (j = 1 ; j <= i ; j++ )
	   for (k = 1 ; k <= i ; k ++)
		   for (n = 1 ; n <= i ; n ++)
		   {  if (a[n] == 0 )
			   continue;
            else 
		    {
			   for (l = 1 ; l <= i; l++)
				   for(m = 1 ; m <= i ; m++)
				   {  if (a[m] == 0)
					   continue;
			        else 
				    {
				      x = a[n]*100+a[k]*10+a[j];
				      y = a[m]*10+a[l];
					  w = x*y;
					  w1 = a[l]*x;
					  w2 = a[m]*x;
					  z = w;
		             int ok = 1 ;
                        
					 while ( z > 0)
					 {
					    int t = z%10,t1;
                        for (t1 = 1 ; t1 <= i ; t1 ++ )
							 if (a[t1] == t)
								 break;
		             	if (t1 == i+1)
                             ok = 0;
						z /= 10;
                                 					    
					 }
				    
                    z = w1;      
					 while (z > 0)
					 {
					    int t = z%10,t1;
                        for (t1 = 1 ; t1 <= i ; t1 ++ )
							 if (a[t1] == t)
								 break;
		             	if (t1 == i+1)
                             ok = 0;
						z /= 10;
                                 					    
					 }
				
				   
                     z = w2;    
					 while (z > 0)
					 {
					    int t = z%10,t1;
                        for (t1 = 1 ; t1 <= i ; t1 ++ )
							 if (a[t1] == t)
								 break;
		             	if (t1 == i+1)
                             ok = 0;
						z /= 10;
                                 					    
					 }
				       if(ok == 1)
						 printf("%d %d %d\n",x,y,w);
				   
				   }
				 }
            }
          }
     return 0 ;
}
