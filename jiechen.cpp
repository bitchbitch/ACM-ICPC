#include <stdio.h>
int main(){
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n , m ; 
	scanf("%d %d",&n,&m);
	//printf("***");
	int k = 1; 
	for(int i =1 ;i<= m+1; i ++)
		k *= 10;
	long long  hehe = 1; 
	for(int i= 1;i <= n;i ++)
	{
	   hehe *= i ;
	   for(;;)
	   {
         if(hehe % 10 == 0)
          hehe /= 10;
		 else break;
	   }
	   hehe %= 1000000000 ; 
	}
    for(int i= 1;i< m;i ++)
		hehe /= 10;
	printf("%lld\n",hehe%10);
  }
return 0;
}
