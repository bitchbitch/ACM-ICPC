#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int Rand(int be ,int en)
{
   int a =  rand() % (en - be + 1);
   return a + be;
}
int main()
{
	int n;
	srand((int)time(NULL));  //调用srand()函数，以系统时间为随机种
    freopen("数字的个数.in","w",stdout);
    int t =10000;
    printf("%d\n",t);
	for(int i = 1; i <= t ;i ++)
	{
	   int a, b ; 
	   a = Rand(1, 999999);
	   b = Rand(a+1,1000000);
	   printf("%d %d %d\n",a,b,Rand(0,9)); 
	}
	
	return 0;
}

