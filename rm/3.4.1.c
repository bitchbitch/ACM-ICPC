#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b)
{

    return *(int*)a - *(int*)b;

}
int main()
{
    int i = 1, c[1000], a[100], b[100] = {0};
    while (scanf("%d",&c[i]) != EOF)
	{
	   i = i +1;

	}
	qsort(c,i,sizeof(int),comp);
	int j , k ,t = 1  ;
	printf("\n");
	for (j = 1 ; j < i ; j++)
	{
		int ok = 1 ;
	    for ( k = 1; k < j;  k++ )
			if (c[k] == c[j])
				ok = 0 ;
		if (ok)
			a[t++] = c[j];

	} 
	for (k = 1; k < t ; k ++)
		for (j = 1 ; j < i ; j ++)
			if (c[j] == a[k])
				b[k]++;
    for (j = 1 ; j < t; j++)
		printf("%d %d\n", a[j], b[j]);
	return 0;
   
}
