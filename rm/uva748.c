// File Name: uva748.c
// Author: darkdream
// Created Time: 2013年01月27日 星期日 11时15分03秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define clean(b)  memset(b,0,sizeof(b))
char a[100];

int  change(char a[],int  b[])
{
	int i , t = -1, j = 0 ;
	for (i = strlen(a)-1; i >= 0; i--)
		if(a[i] == '.')
		{
			t = i ;

		}
		else 
		{
			b[j++] = a[i] -'0';
		}
  if (t != -1)
     return strlen(a) - t -1 ;
  else return -1 ;
}
int strle(int c[])
{
 int i ;
 for (i = 550 ;i >=0 ;i --)
    if (c[i] != 0)
		break;
 return  i + 1 ;
}

void mu(int c[],int d[], int e[])
{ 
	void print();
	int i ,j, k ,t ; 
	for (i =0 ;i < strle(c) ;i ++)
	{
		int s = 0 ;
		for (j = 0 ; j < strle(d) ;j++)
		{
			t = c[i]*d[j] +s +e[i+j] ;
			s = t / 10 ;
			e[i+j] = t % 10 ;
		}
		for (j = i+j  ; j< 550 ; j++)
		{
			t = e[j] + s;
			s = t /10 ;
			e[j] = t %10 ;
		}

	}

}

void print(int t , int c[])
{

  int i , j ,k ; 
  for (i = 550 ;i >= 0; i --)
	  if(c[i] != 0)
		  break;
  if (i < t -1 )
  {
    printf(".");
    for (k =i ; k < t-1 ; k++)
		printf("0");
  }
  for (j = 0 ; j < t ; j++)
	  if (c[j] != 0)
		  break;
  
  for (; i >= j ; i--)
  {  if (i  ==  t-1)
        printf(".");	   	  
	  printf("%d",c[i]);
  }
  printf("\n");

}


int main(){

	while(scanf("%s",a) != EOF)
	{
		int n , d[600], e[600] , f[600];
		clean(d);
		clean(e);
		clean(f);
		scanf("%d",&n);
		int i , j , k , l  , t;
		t = change(a , d);
        t = t * n ;
		memcpy(e , d ,sizeof(d) );
	   if (n >1)
		mu(d,e,f);
	   else 
		 memcpy(f,e,sizeof(e));
		for (i = 3 ; i <= n; i++)
		{
		  memcpy(d,f,sizeof(f));
		  clean(f);
          mu(d,e,f);
		}
      print(t,f);

	}

	return 0 ;
}
