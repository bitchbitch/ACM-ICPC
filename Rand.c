#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int Rand(int be ,int en)
{
   int a =  rand() % (en - be + 1);
   return a + be;

}
char str[400000];
void ex(int n , int p)
{
   if(p == 0 )
	   return; 
   int k = Rand(50,100);
   for(int i = 0 ;i < n;i ++)
   {
     int temp = Rand(1,100);
	 if(temp >= k)
		 str[2*n - i -1] = 'a' + Rand(0,25);
	 else str[2*n-i - 1] = str[i];
   }
   ex(2*n,p-1);
}
int main()
{
	int n;
	srand((int)time(NULL));  //调用srand()函数，以系统时间为随机种
    // freopen("input.txt","w",stdout);
    int t = 100;
	for(int i = 1; i <= t ;i ++)
	{
	   int n = Rand(1,30);
	   printf("%d\n",n);
	   memset(str,0,sizeof(str));
	   for(int i = 0;i < n;i ++)
	   {
	     str[i] = 'a' + Rand(0,25);
	   }
	   ex(n,Rand(1,30));
       puts(str);
	
	}
	
	return 0;
}

