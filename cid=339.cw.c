#include<stdio.h>
int main()
{
	char ch1,ch2,a[100][100],k;
	int i,n,j,t=1;
	while(scanf("%d %c %c",&n,&ch1,&ch2)!=EOF)
	{	if(t!=1)
		printf("\n");
		t++;
		if(n==1)
			printf("%c\n",ch1);
		else
		{if((n+1)/2%2==0)
			{
				k=ch1;
				ch1=ch2;
				ch2=k;
			}
			a[1][1]=ch1;a[1][n]=ch1;
			for(i=2;i<n;i++)
				a[1][i]=ch1;
			for(i=2;i<=(n+1)/2;i++)
		{	if(i%2==0)
				{
					for(j=1;j<i;j++)
						a[i][j]=a[i-1][j];
					for(j=i;j<=n-i+1;j++)
						a[i][j]=ch2;
					for(j=n-i+2;j<=n;j++)
						a[i][j]=a[i-1][j];
				}
				else 
				{
					for(j=1; j<i; j++)
						a[i][j]=a[i-1][j];
					for(j=i; j<=n-i+1; j++)
						a[i][j]=ch1;
					for(j=n-i+2;j<=n;j++)
						a[i][j]=a[i-1][j];
				}

			}	
			a[1][1]=' ',a[1][n]=' ';
			for(i=1;i<=(n+1)/2;i++)
			{for(j=1;j<=n;j++)
				printf("%c",a[i][j]);
				printf("\n");
			}
			for(i=(n+1)/2+1;i<=n;i++)
			{for(j=1;j<=n;j++)
				printf("%c",a[n-i+1][j]);
				printf("\n");
			}
		}
	}
	return 0;
}
