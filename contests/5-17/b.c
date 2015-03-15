#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
int cmp (const void *a , const void *b)
{
	return *(int *)a - *(int *)b;
}
int d[13];
int main()
{
	int t  , n , m , count , i , j , k;

	scanf("%d" , &t);
	while(t--)
	{   
		scanf("%d%d" , &n , &m);
		int max = -1;


		for(i=1 ; i<=n/2+1 ; i++)
		{int sum = 0;
			j=n-i;


			k=m;

			d[0]=i;
			d[1]=j;
			d[2]=k;
			d[3]=abs(i-j);
			d[4]=abs(i-k);
			d[5]=abs(k-j);
			d[6]=i+j;
			d[7]=i+k;
			d[8]=k+j;
			d[9]=i+j+k;
			d[10]=abs(i+j-k);
			d[11]=abs(i+k-j);
			d[12]=abs(j+k-i);  
		  qsort(d,13,sizeof(int),cmp);
		  if(d[0] != 0 )
		     sum = 1; 
		   for(int i= 1;i <= 12; i ++)
			   if(d[i] != d[i-1])
				   sum ++;
          if(sum > max)
			  max = sum;
		}



		for(i=1 ; i<=m/2+1 ; i++)
		{int sum = 0;
			j=m-i;


			k=n;

			d[0]=i;
			d[1]=j;
			d[2]=k;
			d[3]=abs(i-j);
			d[4]=abs(i-k);
			d[5]=abs(k-j);
			d[6]=i+j;
			d[7]=i+k;
			d[8]=k+j;
			d[9]=i+j+k;
			d[10]=abs(i+j-k);
			d[11]=abs(i+k-j);
			d[12]=abs(j+k-i);  
		   qsort(d,13,sizeof(int),cmp);
		   if(d[0] != 0)
		      sum = 1; 
		   for(int i= 1;i <= 12; i ++)
			   if(d[i] != d[i-1])
				   sum ++;
           if(sum > max)
			  max = sum;

		}
		printf("%d\n",max);

	}
	return 0 ;
} 
