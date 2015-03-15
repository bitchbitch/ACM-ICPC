#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define N  40000
int a[N+10],b[201][201] = {0},b1[201][201],c[201][201] ={0} ,x[N],y[N],step[N];
void print()
{
   int  i , j, t;
   for (i =1 ; i <= N ;i ++)
	   a[i] =  i ;
   t = sqrt(N);
   a[1] = 0 ;
   for (i = 2; i<= t; i ++)
   {
	   if (a[i]!=0)
       { j = i*i;
	   while (j <=N)
	   {
	     a[j] = 0 ; 
		 j = j +i ;
	   }
     }	
   }
   i = 1 ; 
   j = 0 ; 
   t = N ; 
   while (t >= 1 )
   {
     while (j +1 <= 200 && b[i][j+1] == 0)
	 {   c[i][j+1] = t;
		 if ( a[t] == 0)
			 b[i][++j] =  -1 , t--;
         else b[i][++j] = a[t],t --;
	 }			
     while (i +1 <= 200 && b[i+1][j] == 0)
	 {	  c[i+1][j] = t ; 
		 if ( a[t] == 0)
			  b[++i][j] =  -1 , t--;
		 else b[++i][j] = a[t], t --;
	 }			
     while (j - 1 >= 1 && b[i][j-1] == 0)
	 {	 c[i][j-1] = t ;
		 if ( a[t] == 0)
			  b[i][--j] =  -1 , t--;
		 else b[i][--j] = a[t], t --;
	 }
     while (i -1 >= 1 && b[i-1][j] == 0)
	 {	  c[i-1][j] = t ;
		 if ( a[t] == 0)
			  b[--i][j] =  -1 , t--;
		 else b[--i][j] = a[t], t--;
     }
   }
}

int main()
{
   print();

   int i , j , k  , l , m, n ,ca = 0 ;
   while (scanf("%d %d",&n,&m) != EOF)
   {    ++ca;
      memset(x,0,sizeof(x));
	  memset(y,0,sizeof(y));
	  
	   for (i =1 ; i<=200 ; i++)
		   for (j = 1 ; j<=200 ;j++)
		   {
		       b1[i][j] = b[i][j];
			   if (c[i][j] == n)
			  {
			   x[1] = i ; 
			   y[1] = j ;
			   
			  }
		   }
      memset(step,0,sizeof(step));
	  int q =  0;
	    k  = 1 ;
       b1[x[1]][y[1]] = 0 ;

	   for (i =1 ; i <= k ; i++)
	   {  
	     
	     if (x[i]+1 <= 200 && b1[x[i]+1][y[i]] == -1)
		  {  
			 step[k+1] = step[i]+1; 
			 if (c[x[i]+1][y[i]] == m)
			 {   q = 1 ;
				 break;
			 }
			 b1[x[i]+1][y[i]]= 0 ;
			 k = k+1;
			 x[k] = x[i]+1;
			 y[k] = y[i];
         }

         
	     if (x[i]-1 >= 1 && b1[x[i]-1][y[i]]== -1)
		 {  step[k+1] = step[i]+1;
			 if (c[x[i]-1][y[i]] == m)
			 {   q = 1 ;
	             break;
			 }
			 b1[x[i]-1][y[i]]= 0 ;
			 k = k+1;
			 x[k] = x[i]-1;
			 y[k] = y[i];
         }
	
        
	     if (y[i]+1 <= 200 && b1[x[i]][y[i]+1]== -1)
		 {  
			 step[k+1] = step[i]+1;
			 if (c[x[i]][y[i]+1] == m)
			 {   q = 1 ;
				 break;
			 }
			 b1[x[i]][y[i]+1]= 0 ;
			  k =k +1;
			 x[k] = x[i];
			 y[k] = y[i]+1;
         }

        
	     if (y[i]-1 >= 1 && b1[x[i]][y[i]-1]== -1)
		 { 
			 step[k+1] = step[i]+1;
			 if (c[x[i]][y[i]-1] == m)
			 {   q = 1 ;
				 break;
			 }
			 b1[x[i]][y[i]-1]= 0 ;
			 k = k + 1;
			 x[k] = x[i];
             y[k] = y[i]-1;
         }

       
        
	   }
		    
	   if (q==1)
		   printf("Case %d: %d\n",ca,step[i]+1);
	   else 
		   printf("Case %d: impossible\n",ca);
    
   }
   
 return 0 ;
}
