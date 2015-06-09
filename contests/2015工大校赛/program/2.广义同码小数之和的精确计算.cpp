#include<stdio.h>
int main() 
{ int a,d,i,j,k,m,n,p[10];long s[50000];
  printf("   请输入整数d,n: ");
  scanf("%d,%d",&d,&n);
  a=d;k=0;
  while(a>0)
{ k++;p[k]=a%10;a=a/10;}
  for(j=0;j<=k*n;j++) s[j]=0;     // s[0]为整数部分
  for(i=0;i<=n-1;i++)
  for(j=1;j<=k;j++)
     s[i*k+j]=(n-i)*p[k+1-j];     // 小数点后各位求和
  for(j=k*n;j>=1;j--)             // 加完n个数从后往前统一进位
	{ s[j-1]=s[j-1]+s[j]/10;s[j]=s[j]%10;}
  printf("   s(%d,%d)=%ld.",d,n,s[0]);
  m=k*n;
  if(m>10) m=20;
  for(j=1;j<=m;j++) 
     printf("%ld",s[j]);
}

