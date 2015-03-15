#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 200005
int a[maxn];
int main()
{
    int t; 
    scanf("%d",&t);
    for(int CASE = 1; CASE <= t; CASE ++){
        int n ;
        int sum  = 0 ; 
		for(int i = 1;i <= n;i ++)
		{
		  int temp ; 
		  scanf("%d",&temp);
		  sum += temp;
		}
		if(sum <= 0 )
			printf("0\n");
		else printf("%d\n",sum);
	}
    return 0 ; 
}
