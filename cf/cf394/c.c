// File Name: c.c
// Author: darkdream
// Created Time: 2014年02月21日 星期五 00时37分00秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int num[10000];
int map[2000][2005];
int main(){
	int n , m ; 
	scanf("%d %d",&n ,&m );
	int a, b,c ;
	a = b = c = 0 ; 
	for(int i = 1 ;i <= n ; i ++)
		for(int j = 1;j <= m ;j ++)
		{
			int temp ,k;
			scanf("%1d",&temp);
			scanf("%1d",&k);
			k = temp  + k ; 
			if(k == 0)
				a ++ ; 
			if(k == 1)
				b ++ ; 
			if(k == 2)
				c ++;
		}
	memset(num,0,sizeof(num));
	int max = 0 ; 
	for(int i = 1;i <=  n;i ++)
	{
		int tmax = max;
		for(int j = 1; j <= 2*m ;j +=2)
		{
			if(num[j] == num[j+1])
			{
				if(c)
				{
					c-- ; 
					map[i][j] = 1; 
					map[i][j+1] =1; 
				}else if(b)
				{
					b -- ;
					map[i][j] = 1; 
					map[i][j+1] = 0 ;
				}else if(a)
				{
					a--;
				}
			}
			else if(num[j] != num[j+1])
			{
				if(num[j] > num[j+1])
				{
					if(num[j] < max)
					{
						if(b)
						{
							b-- ; 
							map[i][j] = 0; 
							map[i][j+1] =1; 
						}else if(c)
						{
							c -- ;
							map[i][j] = 1; 
							map[i][j+1] = 1 ;
						}else if(a)
						{
							a--;
						}

					}else {
				      if(b)	
						{
							b-- ; 
							map[i][j] = 0; 
							map[i][j+1] =1; 
						}else if(a)
						{
						  a --;
						}else 
						{
							c -- ;
							map[i][j] = 1; 
							map[i][j+1] = 1 ;
						}
					
					}
				}else {
					if(num[j] < max)
					{
						if(b)
						{
							b-- ; 
							map[i][j] = 1; 
							map[i][j+1] =0; 
						}else if(c)
						{
							c -- ;
							map[i][j] = 1; 
							map[i][j+1] = 1 ;
						}else if(a)
						{
							a--;
						}

					}else{
				      if(b)	
						{
							b-- ; 
							map[i][j] = 1; 
							map[i][j+1] =0; 
						}else if(a)
						{
						  a --;
						}else 
						{
							c -- ;
							map[i][j] = 1; 
							map[i][j+1] = 1 ;
						}

					}
				}

			}
			num[j] += map[i][j];
			num[j+1] += map[i][j+1];
			if(num[j] > tmax)
				tmax = num[j];
			if(num[j+1] > tmax) tmax = num[j+1];
		}
		max = tmax;
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= 2*m; j += 2)
		{
			if(j!= 1)
				printf(" ");
			printf("%d%d",map[i][j],map[i][j+1]);

		}
		printf("\n");
	}
	return 0 ;
}
