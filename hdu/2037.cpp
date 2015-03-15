
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
struct node{
  int be,en;
}List[200];
int cmp(node x,node y)
{
   return x.en < y.en;
}
int main(){
   int n; 
   while(scanf("%d",&n) != EOF)
   {
     if(n == 0)
		 break;
	 for(int i = 1;i <= n;i ++)
         scanf("%d %d",&List[i].be ,&List[i].en);
     sort(List+1,List+n+1,cmp);
	 int en = -1;
	 int sum = 0 ; 
	 for(int i = 1;i <= n;i ++)
	 {
	    if(List[i].be >=en)
		{
		  sum ++ ; 
		  en = List[i].en;
		}
	 }
	 printf("%d\n",sum);
   }
return 0;
}
