// File Name: c.c
// Author: darkdream
// Created Time: 2013年06月15日 星期六 12时37分42秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	long long int x, y , m;
	while(scanf("%I64d %I64d %I64d",&x,&y,&m)!= EOF)
	{
		long long int temp;
		if(x < y )
		{
			temp  =  x; 
			x = y ; 
			y = temp;
		}
		if(x <= 0 && y <= 0 && m > x )
		{ 
			printf("-1\n");
			return 0;
		}
		
		long long  step = 0 ;
		if(y <= 0 && x >  0  && m > x)
		{
	      step = ceil((-1.0*y)/x );
		  y = y + step * x;
		}
 
		if(x < y  )
		{
			temp  =  x; 
			x = y ; 
			y = temp;
		}
		while(x < m )
		{
			temp = x+y; 
			if(temp >  x)
			  {
			     y  = x ;
				 x = temp;
			  }
			else
			 {
		       y = temp;	
			 }
			step++;
		}
		printf("%I64d\n",step);
	}
	return 0 ;
}
