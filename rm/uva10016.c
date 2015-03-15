// File Name: uva10016.c
// Author: darkdream
// Created Time: 2013年03月03日 星期日 15时04分19秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
bool a[900];
int  b[900];
int  c[900];
int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  int n , m; 
  while(scanf("%d %d",&n,&m) !=EOF)
  {
	double k = 0; 
    memset(a,0,sizeof(0));
   for (int i = 1;i <= n ; i++)
	   k += log(i);
   k =ceil( k /log(m) + 1e-8);
   for (int i = 2;i <= sqrt(800); i++)
   {
      if(a[i] == 0)
	  {
	    int t = i* i ;
		while(t <= 800)
	      {
		    a[t] = 1; 
			t = t +i ;
		  }	
	  }
   }
   int t = 1; 
   memset(c,0,sizeof(c));
   for(int i = 2; i <= 800 ; i ++)
	   if(a[i] == 0)
	   {
          b[t++] = i;
	   }
   for(int i = 1; i < t  ;i ++)
   {  if( m % b[i] == 0)
	   {
	     c[b[i]]++;
		 m = m /b[i];
		 i = i -1;
	   }
      if(m < b[i])
		  break;
   }
   long long int  min = 100000000000;
   for(int i = 1 ;i < t; i ++ )
   {
      if(c[b[i]] != 0)
	  {   
		  int temp = n, p = 0 ;
		  while ( temp / b[i] >= 1)
		    {   p += temp / b[i];
                temp = temp /b[i]; 
			}
		  p = p / c[b[i]];
			 if (p < min)
	  			 min = p;
	  }
   }
   

   printf("%lld %d\n",min,(int)k);
  }
return 0 ;
}
