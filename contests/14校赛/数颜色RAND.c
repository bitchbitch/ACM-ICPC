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
    freopen("数颜色.in","w",stdout);
    int t = 5;
    printf("5\n");
	for(int i = 1; i <= t ;i ++)
	{
		int n = Rand(1,100000);
		int T = Rand(1,30);
		int O = Rand(1,100000);
		printf("%d %d %d\n",n,T,O);
		for(int i = 1;i <= O ;i ++)
		{
		    int is = Rand(0,1);
				int A = Rand(1,n);
				int B = Rand(A,n);
			if(is)
				printf("C %d %d %d\n",A,B,Rand(1,T));
			else printf("P %d %d\n",A,B);
		}
	
	}
	
	return 0;
}

