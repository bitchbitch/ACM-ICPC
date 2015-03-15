#include<stdio.h>
#include<math.h>
int main()
{  long long  n,m,i,f=0;
scanf("%lld",&n);
while(n--)
{ f=0; 
  scanf("%lld",&m);
  if(m==2||m==3)
  f++;
  else if(m==0||m==1)
  f=f+0;
  else
  { 
   int k=sqrt(m);
    printf("%d\n",k);   
for(i=2;i<=k;i++)
      if(m%i==0)
     {break;
      
     }
  }
}
   printf("%lld\n",f);
   return 0;
}
