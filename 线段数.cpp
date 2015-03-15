// File Name: 线段数.cpp
// Author: darkdream
// Created Time: 2013年12月21日 星期六 23时46分10秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;
double   a[100][100];
int  n ,m ; 
void do1()
{
	printf("自乘\n");
	printf("1..行  2..列\n");
	int  x, y;
	double z;
	scanf("%d %d %lf",&x,&y,&z);
	if(x == 1)
	{
		for(int i = 1;i <= m;i ++)
			a[y][i] *= z;
	} else {
		for(int i = 1;i <= n;i ++)
			a[i][y] *= z;
	}
}
void do2()
{
	printf("相加减\n");
	printf("1..行  2..列\n");
	int x,y,y1;
	double z1;
	scanf("%d %d %d %lf",&x,&y,&y1,&z1);
	if(x == 1 )
	{
		for(int i =1; i <= m; i ++)
		{
			a[y][i] = a[y][i]  + a[y1][i] * z1;
		}
	}else  
	{
		for(int i =1; i <= n; i ++)
		{
			a[i][y] = a[i][y]  + a[i][y1] * z1;
		}
	     
	}
}
void do3()
{
	printf("交换\n");
		printf("1..行  2..列\n");
	int x, y ,z;
    scanf("%d %d %d",&x,&y,&z);
	if(x == 1)
	{
		for(int i = 1;i <= m;i ++)
		{
			double temp = a[y][i];
			a[y][i] = a[z][i];
			a[z][i] = temp;

		}
	} else {
		for(int i = 1;i <= n;i ++)
		{ double temp = a[i][y];
			a[i][y] = a[i][z];
			a[i][z] = temp;
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i =1 ;i  <= n;i ++)
		for(int  j = 1; j<= m;j ++)
			scanf("%lf",&a[i][j]);
	int temp ;
		while(scanf("%d",&temp) != EOF)
		{
			if(temp ==1)
				do1();
			else if(temp == 2) 
				do2();
			else  do3();
			for(int i =1 ;i  <= n;i ++)
			{ for(int j = 1; j<= m;j ++)
				printf("%10.3lf ",a[i][j]);
				printf("\n");
			}
		}
	return 0;
}
