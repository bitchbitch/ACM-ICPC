#include<stdio.h>
int main()
{ int i,j,k,m,n,x,a[200];
  char b[200];
  printf("  请输入整数：");
  scanf("%s",b);              //  以字符串方式输入高精度整数 
  for(n=0,i=0;b[i]!='\0';i++)
    {n++;a[i]=b[i]-48;}
  printf("  删除数字个数:  ");scanf("%d",&k);
  printf("  以上%d位整数中删除%d个数字分别为: ",n,k);
  i=0;m=0;x=0;
  while(k>x && m==0)
   {i=i+1;
    if(a[i-1]>a[i])         	// 出现递减, 删除左边的数字 
      { printf("%d, ",a[i-1]);
        for(j=i-1;j<=n-x-2;j++)// 删除一数字后，后面的数字前移
          a[j]=a[j+1];
        x=x+1;               	// x统计删除数字的个数 
        i=0;                  	// 从头开始查递增区间 
      }
   if(i==n-x-1) m=1;           	// 已无递减区间,m=1脱离循环      
   }
 printf("\n  删除后所得最小数: ");
 for(i=1;i<=n-k;i++)         	// 打印剩下的左边n?k个数字 
   printf("%d",a[i-1]);
 printf("\n");
}

