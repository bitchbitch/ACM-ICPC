#include<stdio.h>
int main()
{
int a,m,n,i,j,k;
scanf("%d",&m);
for(k=1;k<=m;k++)
{if(k!=1)
printf("\n");
scanf("%d",&n);
a=0;
for(i=1;i<(n+1)/2; i++)
{
for(j=1; j<=a;j++)
printf("0");
printf("X");
for(j=1;j<=n-2*a-2; j++)
printf("0");
printf("X\n");
a++;
}
for(i=1;i<=a; i++)
printf("0");
printf("X");
printf("\n");
for(i=1;i<(n+1)/2; i++)
{a--;
for(j=1; j<=a;j++)
printf("0");
printf("X");
for(j=1;j<=n-2*a-2; j++)
printf("0");
printf("X\n"); 
} 

}
return 0;
}
