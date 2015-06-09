#include <stdio.h>
#include <math.h>
int prime(int t)
{int i,flag;
 if (t==2) flag=1;
 else
 {flag=1; 
  for (i=2;i<=sqrt(t);i++)
     if (t%i==0) {flag=0;break;}
 }
 return flag;
}
int main()
{ long c,d,i,j,f,t,f1,i1,max;
  scanf("%ld %ld",&c,&d);
  puts("***");
  while (prime(c)) c++;
  puts("***");
  f=c;max=0;
  //bug 出现于 区间在最前面  需要改正
  for(i=c;i<=d;i++)
     {
         printf("%ld %ld\n",i,d);
      if(prime(i))                           
        { if(i-f>max) 
            {max=i-f;f1=f;i1=i-1;}
          f=i+1;                
        }                                   
     }
  puts("***");
  if (!prime(d)&&(d-f+1>max))
    {max=d-f+1;f1=f;i1=d;}
  printf("%ld\n",max);
  printf("[%ld,%ld]\n",f1,i1);
 }

