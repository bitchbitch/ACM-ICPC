#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct xy
{
  int x,y,id;
  long long int sum;
  
};
int comp(const void *a,const void *b)
{
 return (*(xy *)a).x- (*(xy *)b).x;
}

int comp1(const void *a,const void *b)
{
 return (*(xy *)a).y- (*(xy *)b).y;
}

  

struct xy a[100010]={0};
long long sumx[100010]={0},sumy[100010]={0};

int main()
{ 
	int t ;
	scanf("%d",&t);
	while (t--)
	{	int n,i,j;
		memset(a,0,sizeof(a));
		memset(sumx,0,sizeof(sumx));
		memset(sumy,0,sizeof(sumy));
	   long long int min;
		scanf("%d",&n);
        for (i = 0; i < n ;i ++)
		 scanf("%d %d",&a[i].x,&a[i].y);

		qsort (a,n,sizeof(a[0]),comp);
		sumx[0] = a[0].x;
		for (i = 1; i < n ; i++ )
			sumx[i] = sumx[i-1]+ a[i].x;

		a[0].sum = sumx[n-1] - 1LL*n*a[0].x;
		 for (i = 1;i < n ; i ++  )
		    a[i].sum = 1LL*i*a[i].x-sumx[i-1] + (sumx[n-1]-sumx[i]) - 1LL*(n-i-1)*a[i].x;
		
		qsort (a,n,sizeof(a[0]),comp1);
         sumy[0] = a[0].y;
		for (i = 1; i < n;i ++)
			sumy[i] =  sumy[i-1] + a[i].y;

		a[0].sum += sumy[n-1] - 1LL*n*a[0].y;
       for (i = 1;i < n ; i ++  )
	     a[i].sum += 1LL*i*a[i].y-sumy[i-1] + (sumy[n-1]-sumy[i])- 1LL*(n-i-1)*a[i].y;
       
	   min = a[0].sum;
		for (i = 1;i <n ; i++ )
			if (a[i].sum <min)
				min = a[i].sum;
	
    printf("%lld\n",min);

	}
	return 0 ;
}
