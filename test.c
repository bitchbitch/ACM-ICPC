#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Rand(int be ,int en)
{
   int a =  rand() % (en - be + 1);
   return a + be;

}
int main()
{
	int n;
	srand((int)time(NULL));  //调用srand()函数，以系统时间为随机种
 //   freopen("input.txt","w",stdout);

    printf("%d",Rand(0,1));	
	return 0;
}
