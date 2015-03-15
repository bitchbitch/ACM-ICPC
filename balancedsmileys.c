// File Name: balancedsmileys.c
// Author: darkdream
// Created Time: 2013年01月26日 星期六 09时10分05秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   int n, j ;
    scanf("%d",&n);
	getchar();
	FILE *p1 = fopen("output.txt","w");
	for (j = 1;j <= n; j++)
	  {
	    char a[200];
		int i , k , l , m , p ,q , sum = 0 ,x,y;
		gets(a);
	    if (strlen(a) == 0)
			fprintf(p1,"Case #%d: YES\n",j);
		else 
		{
		   for (l = 0 ; l< strlen(a) ;l ++)
		   {
		      if (a[l] == '(' )
				  break;
		   }
		   
		   for (k = 1 ; k < l ; k ++ )
			   if (a[k-1] != ':' && a[k] == ')')
				   break;
		   if (k < l )
		   {  
	   	      fprintf(p1,"Case #%d: NO\n",j);
		      continue;
		   }


		
		   for (m = strlen(a) ; m >= 0;  m --)
		   {
		      if (a[m] == ')' )
				  break;
		   }
		   
		   for (k = strlen(a) ; k > m ; k -- )
			   if (a[k-1] != ':' && a[k] == '(')
				   break;

		   if (k > m)
		   {  
	   	      fprintf(p1,"Case #%d: NO\n",j);
		      continue;
		   }
		   p = 0 ;
		   q = 0 ;
		   x = 0 ; 
		   y = 0 ;
		   for (i  = l ; i <= m ; i ++)
		   {
		       if (a[i] == '(')
			   {   x ++;
			      if (i >= 1 && a[i-1] == ':')
					  p++;
			   }
			   if (a[i] == ')')
			   {
			        y ++;
					if (a[i-1] == ':' )
					 q ++;
			   }   
		   }
		   if (x - y > 0 )
            {
			  if  (p >= x - y)
				  fprintf(p1,"Case #%d: YES\n",j);
			  else 
				  fprintf(p1,"Case #%d: NO\n",j);
			}
		   else 
		   {
		      if (q >= y-x)
				  fprintf(p1,"Case #%d: YES\n",j);
			  else 
				  fprintf(p1,"Case #%d: NO\n",j);
		   }

		   
		}
			
	   
	  }
	fclose(p1);
return 0 ;
}
