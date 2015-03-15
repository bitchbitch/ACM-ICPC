#include <stdio.h>
#include <math.h>
int a[5010]={0};
int main()
{
  int t ,i,j,k,l;
  a[1] = 1 ;
  a[2] = 2;
   for (i = 3; i <5000 ; i++)
   {
        l =i/2;
		for (j = 2 ; j<= l ; j++ )
			if(i %j == 0)
				a[i]++;
		a[i]= a[i]+2;
	
   }
  scanf("%d",&t);
  while (t--)
  { int n ,m ,max = 0  ,ti; 
    scanf("%d %d",&n, &m);
	for ( i = n ;i <= m ;i ++)
		if (a[i]> max)
		{
		 max = a[i];
		 ti =  i ;

		}
    
	 printf("%d\n",ti);
  }
  return 0 ;
}
