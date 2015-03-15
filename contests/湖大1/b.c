// File Name: b.c
// Author: darkdream
// Created Time: 2013年07月16日 星期二 12时13分40秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int a  ;
	while(scanf("%d",&a) != EOF)
	{
		int b ,temp;
		int d, time = 1;
		double p; 
        char c ;
		int okd = 1 ;
		int okp = 1 ;
		
		while(scanf("%d",&b) != EOF)
		{
			if(time == 1 )
			{   
				d = b - a;
				if(a == 0 )
					okp = 0 ;
				else
					p = b*1.0/a;
			}
			else 
			{
				if(okd &&b - a != d )
					okd = 0 ;
				if(okp && (a == 0 || fabs(p-b*1.0/a) > 1e-7))
				{
					okp = 0 ;
				}

			}
           a = b;
			time ++;
			c = getchar();
			if(c == '\n')
				break;

		}
		if(okd == 1 )
			printf("%d\n",a + d);
		else if (okp == 1)
		{
			double t = a * p;
			if(fabs(t - int(t)) < 1e-8)
			 printf("%d\n",(int)t);
		   else printf("42\n");
		}
		else  printf("42\n");
	}
	return 0 ;
}
