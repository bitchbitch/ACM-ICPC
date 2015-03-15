#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int comp(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}
int a[17000000],b[17000000];
int main()
{
   int  n ;
   int a1[4002],a2[4002],a3[4002],a4[4002];
   while (scanf("%d",&n)!= EOF)
   {
      int i, j, k, l  ; 
	  for (i = 0 ; i < n ; i ++)
		  scanf("%d %d %d %d",&a1[i],&a2[i],&a3[i],&a4[i]);
	   l = 0 ;
	  for (i = 0 ;i < n ; i ++ )
		  for (j = 0 ; j < n; j++ )
		  { b[l++] = a3[i]+a4[j];
            a[l-1] = a1[i]+a2[j];
		  }
	  l = l ;
	  qsort(a,l,sizeof(int),comp);
	  qsort(b,l,sizeof(int),comp);
	  
	  int sum = 0 ;
     int p = l-1;
	  for (i = 0 ; i < l ; i++)
	  { 
		 while (a[i] + b[p] > 0 && p>=0) p--;
		 if (p < 0)
			 break;
         int temp = p ;
		 while (temp >= 0 &&a[i]+b[temp] == 0 )
		 {
		   sum ++;
		   temp--;
		 }
		
         
	  }	
	  printf("%d\n",sum);
    }
   return 0 ; 
}
