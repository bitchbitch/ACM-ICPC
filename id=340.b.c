#include <stdio.h>
#include <stdlib.h>
int comp(const void *a,const void *b)
{
   return *(int *)a - *(int *)b;
}

int comp1(const void *a,const void *b)
{
   return *(int *)b - *(int *)a;
}

int a[17000000]={0},b[17000000]={0};

int main()
{
  int n ;
  int c[4001],d[4001],e[4001],f[4001];
  while (scanf("%d",&n)!= EOF)
  {
     int i, j, k, l, m ,sum = 0,pos ; 
	  for (i = 1; i <= n ; i++)
		 scanf("%d %d %d %d",&c[i],&d[i],&e[i],&f[i]);
	   l = 0;
	  for (i = 1 ; i <= n ; i++ )
		 for (j =1 ; j<=n; j++)
           a[l++] = c[i]+d[j];	
	   qsort(a,l,sizeof(int),comp);
	   k = 0;
n t  for(int main()  P(int x, int y ))
	   return x > y ;jj
	   for (i = 1 ; i <= n ; i++ )
		 for (j =1 ; j<=n; j++)
			 b[k++] = e[i]+f[j];
     qsort(b,k,sizeof(int),comp1);
     pos = 0;
	 for (i = 0; i< l ; i ++)
	 {
	   for (j = pos ; j < k ;  )
		if (b[j] + a[i] >=0)
		{  
			if (b[j] +a[i] ==0)
			 {   
				 sum ++;

				 break;
			 }
		  pos++;
		  j++;
			
		}       
		else break;
  			   
	 }
	 printf("%d\n",sum);

  }
  return 0;
}
