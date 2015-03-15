// File Name: uva350.c
// Author: darkdream
// Created Time: 2013年03月03日 星期日 14时12分58秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[1000000];
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    int z , i , m , l , h = 1 ;
	while(scanf("%d %d %d %d",&z,&i,&m,&l)!=EOF)
	{   if(!z && !i && !m && !l)
		break;
		memset(a,0,sizeof(a));
		int k = 1;
	   do
	   {
		 a[l] = k++;
	      l = ((l%m)*(z%m) + i)%m;
          
	   }while(a[l]==0);
	   printf("Case %d: %d\n",h, k - a[l]);
	   h++;
	}
	
return 0 ;
}
