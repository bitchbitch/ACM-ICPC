// File Name: 2678.c
// Author: darkdream
// Created Time: 2013年09月10日 星期二 22时55分03秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int a[200];
int b[200];
int temp[200];
char str[200];
int count = 0 ; 
int  cmp()
{
      for(int i = 100 ;i >= 0 ;i --)
		{
		  if(a[i] > b[i])
			  return 1; 
		  else if(a[i] < b[i])
			  return -1;
		}
	 return 0 ; 
}
int ise(int *p)
{
	if(p[0] %2 == 0 )
		return 1;
	return 0 ;
}
void mul()
{
   int k = 0  ;
   for(int i = 1;i <= 100 ;i ++)
   {
       k = (a[i] + k)*2 ; 
	   a[i] = k % 10 ; 
	   k = k / 10 ;
   }
}
void div2(int *p)
{
    int  k = 0 ;
    for(int i = 100; i>=1 ;i --)
	{ 
	    k = k *10 + p[i];	
		p[i] = (k)/2;
		k = k % 2; 
	}
}
void jian(int *p ,int *q)
{
      int k = 0 ; 
	  for(int i = 1;i <= 100;i ++)
	  {
	      p[i] = p[i] + k ; 
		  k = 0 ; 
		  if(p[i] < q[i])
		  {
		     k --;
			 p[i]+= 10 ;
		  }
		  p[i] -= p[i];
	  }

}
void gcd()
{
   int k ;
   while(!(k = cmp()))
   {
        if(ise(a))
		{
		  if(ise(b))
		  {
		    count ++;
		    div2(a);
			div2(b);
		  }
		  else 
		  {
		    div2(a);
		  }
		
		}else if (ise(b)){
             div2(b);
		}else {
			 if(k < 0 )
			 {
			   jian(b,a);
			 }
			 else {
			   jian(a,b);
			 }
		}
   
   }
}
int main(){
    int t = 0; 
	while(scanf("%s",str) != EOF)
	{
	  t++;
	  int len = strlen(str);
	  for(int i = 0 ;i < len; i ++)
	      a[len-i] = a[i];
      scanf("%s",str);
	  len = strlen(str);
	  for(int i = 0 ;i < len; i ++)
	      b[len-i] = b[i];
	  gcd();
	  int j = 100;
	  for(;j >= 0 ;j--)
		  if(a[j] != 0)
			  break;
      if(t != 1)
		  printf("\n");
	  for(;j >= 0 ; j -- )
		  printf("%d",a[j]);
	  printf("\n");
	}

return 0 ;
}
