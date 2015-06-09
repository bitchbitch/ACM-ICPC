#include<stdio.h>
int main()
{int m,n,i,j;
 long f[100][100];
 printf(" input m,n(m>n>=8): "); 
 scanf("%d,%d",&m,&n);
 for(i=0;i<=m;i++)
 for(j=0;j<=n;j++)
    if(j==0 && i<8) f[i][j]=1;
    else f[i][j]=0;                  // 确定初始条件
 for(j=1;j<=n;j++)
 for(i=j;i<=m;i++)                   //  实施递推
	if(i==4 && j==1 ||i==3 && j==2)
         f[i][j]=f[i-1][j];
	else if(i==7 && j==1 || i==6 && j==2 || i==5 && j==3)
             f[i][j]=f[i][j-1];
	     else 
             f[i][j]=f[i-1][j]+f[i][j-1];     
 printf("  f(%d,%d)=%ld\n",m,n,f[m][n]);
 }

