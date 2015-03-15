#include <stdio.h>
#include <string.h>
int main()
{
	char a[100][100];
	char c,b;
	int   i , j ,k =1 ,l,n;
	while (scanf("%d %c %c",&n,&c,&b) != EOF)
	{	   
		memset(a,0,sizeof(a));
		a[(n+1)/2][(n+1)/2]=1 ;
		int  t = 1;
		if(k == 1)
			k++;
		else 
			printf("\n");

		if(n ==1)
			printf("%c\n",c);
		else
		{for (i = (n+1)/2 ; i >=1 ; i -- )
			{    int ti = i , tj = i;
				if (t % 2 ==1 )
				{
					while (ti+1 <= n-i+1) a[++ti][tj] = 1;
					while (tj+1 <= n -i+1) a[ti][++tj] = 1;
					while (ti-1 >= i)  a[--ti][tj] =1;
					while (tj-1 >= i)  a[ti][--tj] =1;
					t++;
				}
				else 
				{
					while (ti+1 <= n-i+1) a[++ti][tj] = 0;
					while (tj+1 <= n-i+1) a[ti][++tj] = 0;
					while (ti-1 >= i ) a[--ti][tj] =0;
					while (tj-1 >= i)  a[ti][--tj] =0;
					t++;
				}
			}
			for (i = 1; i <= n ;i ++)
			{ 
				for (j = 1 ; j <=n ; j++)
				{ if((i == 1 && j == 1) || (i == n  && j== 1) ||(i == 1 && j == n )  ||(i == n && j == n) )
					printf(" ");
					else 
					{	if (a[i][j] == 1)
						printf("%c",c);
						else 
							printf("%c",b);
					}

				}printf("\n");
			}
		}

	}
	return 0;

}
