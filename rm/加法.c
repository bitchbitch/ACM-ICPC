// File Name: 加法.c
// Author: darkdream
// Created Time: 2013年01月28日 星期一 21时22分47秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void add(char a[],char b[])
{
     int *x , *y ,i , j ,temp ,k ;
	 k = strlen(a) >strlen(b)? strlen(a)+2:strlen(b)+2;
	 x = (int*)malloc(sizeof(int)*k);
	 y = (int*)malloc(sizeof(int)*k);
     memset(x,0,sizeof(x));
	 memset(y,0,sizeof(y));
	 for (i = 0 ; i < strlen(a) ; i ++)
		 x[i] = a[strlen(a) -i-1] -'0';
	 for (i = 0 ; i < strlen(b) ; i ++)
		 y[i] = b[strlen(b) -i-1] -'0';
	 temp = 0 ;
	 
     printf("%d\n",y[k-1]);
     printf("%d\n",x[k-1]);
	 for (i = 0 ; i < k ; i++)
	 {
	    int t = x[i] + y[i] + temp;
		temp = t / 10;
		x[i] = t % 10;

	 }
     printf("%d\n",x[k-1]);
	 for (j = k-1 ; j>= 1; j--)
		 if (x[j] != 0)
			 break;
	 for (; j>= 0; j--)
		 printf("%d",x[j]);
	 printf("\n");
}

int main(){
    char a[100], b[100];
	gets(a);
	gets(b);
	add(a,b);
	

return 0 ;
}
