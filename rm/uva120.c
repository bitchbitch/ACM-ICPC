// File Name: uva120.c
// Author: darkdream
// Created Time: 2013年02月25日 星期一 19时25分49秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[50] , n , b[50] ;
int comp(const void *a , const void *b)
{
 return *(int *)a - *(int *)b;
}
void change1(int x , int y)
{ void change2(int x);
   if (y == 0)
	   change2(x);
   else
   {
    for(int i = 0 ; i <= y/2 ;i++)
	{
        int temp = b[y-i];
		b[y-i] = b[i];
		b[i] = temp;
	}
    printf("%d ",n-y+1);
	change2(x);
   }

}
void change2(int x)
{
 for (int i = 0 ;i <= x/2 ;i++)
 {
  int temp = b[x-i] ;
  b[x-i] = b[i];
  b[i] = temp ;
 }
 printf("%d ",n-x+1);

}
int main(){

  freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
    n  =  0;
   while(scanf("%d",&a[n]) != EOF)
   {
     if(getchar() == '\n')
     {
		int   k , l;
		for(int j = 0 ;j<= n ;j++)
		{	
		    if (j !=0 )
				printf(" ");
			printf("%d",a[j]);
			b[j] = a[j];
		
		}
		printf("\n");
		qsort(a,n+1,sizeof(int),comp);
		while(1){    
		for(k = n ; k >= 0 ;k--)
				if(b[k] != a[k])
					break;
			if(k == -1)
				break;
			int max = 0, temp ;
			for(int j = k ;j >= 0 ;j--)
			{
			   if(b[j] > max )
			   {
			      max = b[j];
				  temp =  j;
			   }
			}
			change1(k,temp);
		}
	
		printf("0\n");
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		n = 0;
          
	 }
   else
	n++;
   }
return 0 ;
}
