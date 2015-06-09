#include <stdio.h>
#include <math.h>
int m,sum=0,a[10];
long s;

int square(int n)
{int k=sqrt(n);
 if (k*k==n)
    return 1;
 else 
    return 0;
}

// 排列递归函数p(k)  
int p(int k)
{ int i,j,u;
  if(k<=m)
    { for(i=1;i<=9;i++)     
       { a[k]=i;                // 探索第k个数赋值i  
         for(u=0,j=1;j<=k-1;j++)
            if(a[k]==a[j]) {u=1; break;} //  若出现重复数字则u=1  
         if(u==0)               // 若第k数可置i,则检测是否到m个数  
           { if(k==m)           // 若已到m个数时，则打印出一个解 
	              {s=0; 
                   for (j=1;j<=m;j++)
                     s=10*s+a[j];
                   if (square(s)) {sum++;printf("%d ",s);}
	              } 
             else  p(k+1);     // 若没到m个数,则探索下一个数 p(k+1) 
            }
        }
    }
}

int main()
{
  printf(" input m(1=<m<=9):"); scanf("%d",&m);
  p(1);
  printf("\nsum=%d\n",sum);                              
}


 

