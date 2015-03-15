// File Name: 1001.c
// Author: darkdream
// Created Time: 2013年08月17日 星期六 14时59分10秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#pragma comment(linker,"/STACK:102400000,102400000")
int a[2000];
double dosome(double k , double p ,double qw1)
{
	if(qw1*p < 1e-4)
		return 0 ;
	else 
		return qw1*k + dosome(k,p*k,qw1);

}
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int n,m; 
	while(scanf("%d",&n) != EOF)
	{ 

		double qw1 = 0 ;
		for(int i  = 1;i<= n;i ++){
			scanf("%d",&a[i]);
			qw1 += a[i]; 
		} 
		qw1 = qw1*1.0/n;
		scanf("%d",&m);
		int temp ;
		for(int i =1 ;i<= m;i ++)
			scanf("%d",&temp);
		double ans = 0 ;
		if( m == n ){
			if(fabs(qw1-0) < 1e-8)
				printf("0.00\n");
			else 
				printf("inf\n");
		}else {
		   double  k = m*1.0/n;
           ans = qw1 + dosome(k,k,qw1);
	       printf("%.2lf\n",ans);
		}
	}
	return 0 ;
}

