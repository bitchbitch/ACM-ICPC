#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b)
{
   return  *(int*)b- *(int *)a;
}
int main()
{
    int a[3],d;
	 
	 while (scanf("%d %d %d %d",&a[0],&a[1],&a[2],&d)!= EOF)
	  {
        int i ,sum = 0; 
		
		for (i = 1 ; i <= d ; i ++ )
		  {
			  qsort(a,3,sizeof(int),comp);
			  sum = sum +a[0];
			  if (a[0] >= 1)
				  a[0]--;
		  }
		
       printf("%d\n",sum);

	  }

 
  return 0;

}
