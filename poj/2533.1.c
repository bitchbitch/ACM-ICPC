// File Name: 2533.1.c
// Author: darkdream
// Created Time: 2013年07月24日 星期三 20时09分01秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int stack[1001];
   int n ; 
   while(scanf("%d",&n) != EOF)
   {
	   int top = 0 ; 
	   int temp = 0 ; 
       memset(stack,0,sizeof(stack));
       for( int i = 1;i<= n ;i ++)
		{
	       scanf("%d",&temp);	   
	   	   if(!top)
		   {
		     top ++;
			 stack[top] = temp ;
		   }
		   else 
		   {
                 if(temp >= stack[top])
				 {
				   top ++ ; 
				   stack[top] = temp ; 
				 }
				 else 
				 {
				    int low = 1 ,high = top;
					while(low <= high)
					{
					    int mid = (low + high) /2;
					    if(temp > stack[mid])
						{
						  low = mid + 1;
						}
						else 
						{
						  high = mid - 1; 
						}
					}
					stack[low] = temp ;
				 }

		      
		   }
		
		}
   
     printf("%d\n",top);
   }
return 0 ;
}
