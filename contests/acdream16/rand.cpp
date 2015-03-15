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
  freopen("cin.txt","w",stdout);
      
     for(int i =1 ;i <= 10000; i ++)
       printf("%d %d %d\n",Rand(1,1000),Rand(1,1),Rand(1,100000));	
	return 0;
}

