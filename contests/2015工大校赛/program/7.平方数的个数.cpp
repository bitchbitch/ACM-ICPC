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

// ���еݹ麯��p(k)  
int p(int k)
{ int i,j,u;
  if(k<=m)
    { for(i=1;i<=9;i++)     
       { a[k]=i;                // ̽����k������ֵi  
         for(u=0,j=1;j<=k-1;j++)
            if(a[k]==a[j]) {u=1; break;} //  �������ظ�������u=1  
         if(u==0)               // ����k������i,�����Ƿ�m����  
           { if(k==m)           // ���ѵ�m����ʱ�����ӡ��һ���� 
	              {s=0; 
                   for (j=1;j<=m;j++)
                     s=10*s+a[j];
                   if (square(s)) {sum++;printf("%d ",s);}
	              } 
             else  p(k+1);     // ��û��m����,��̽����һ���� p(k+1) 
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


 

