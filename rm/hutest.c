# include <stdio.h>
int main()
{
int n,m,i,j,f=0,a[100][100];
float ave1,sum1,ave2,sum2;
scanf("%d%d",&n,&m);
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("%d",&a[i][j]);
}
}
for(i=0;i<n;i++)
{
sum1=0;
for(j=0;j<m;j++)
{
sum1+=a[i][j];

}
ave1=sum1/m;
printf("%.2f ",ave1);
}
printf("\n");
for(j=0;j<m;j++)
{
sum2=0;
for(i=0;i<n;i++)
{
sum2+=a[i][j];
}
ave2=sum2/n;
printf("%.2f ",ave2);
}
printf("\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
if(a[i][j]>ave2)
  f++;
}
printf("%d\n",f);

return 0;
}
