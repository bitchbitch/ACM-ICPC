// File Name: h.c
// Author: darkdream
// Created Time: 2013年02月17日 星期日 15时24分34秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
  
	char a[2000];
	int d[2000] ={0};
	while(gets(a))
	{
	   char b[300] ={0};
	   int i , j , k , l ;
	   long long int sum = 0 ;
	   gets(b);
	   for (i = 0 ;i < strlen(b); i++)
		   if (b[i] == '0' )
			   b[i+'a'] = '1';
	   j =0;
       for (i = 0;i <= strlen(a); i++ )
		   if(b[a[i]] == '1')
			   d[++j] = i;
	 scanf("%d",&k);
	   if (j <= k)
		   printf("%lld\n",1ll*strlen(a)*(strlen(a)-1)/2);
	   else 
	   {
		   printf("********");
	      sum += d[k+1]*(d[k+1]-1)/2;
		  printf("%lld\n",sum);
         for (i = 2; i+k < j ; i++)
			 sum += (d[i+k-1] - d[i-1] -1 )*(d[i+k]-d[i+k-1]);
	    printf("%lld\n",sum);

			 sum += (d[i+k-1] - d[i] +1)* (strlen(a)-d[i+k-1]+1);
			 printf("%lld\n",sum);
	   }
	}
return 0 ;
}
