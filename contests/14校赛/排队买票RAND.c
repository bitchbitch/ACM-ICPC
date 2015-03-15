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
	srand((int)time(NULL));  //调用srand()函数，以系统时间为随机种
    freopen("排队买票.in","w",stdout);
    int t = 100;
    printf("%d\n",t);
	while(t--)
	{
        int n , m ;
		n = Rand(0,98);
        m = Rand(0,n+2);
        printf("%d %d\n",n,m);	
	}
	return 0;
}

