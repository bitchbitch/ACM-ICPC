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
#define LL long long

using namespace std;
int hs[10005];
int main(){
   int t; 
   scanf("%d",&t);
   for(int ca = 1; ca <= t ;ca ++)
   {
       int n ;
	   scanf("%d",&n);
	   memset(hs,0,sizeof(hs));
	   int temp ; 
	   int mx = -1;
	   int nummax = 0 ;
	   int hsnum = 0 ; 
	   printf("Case #%d:\n",ca);
	   int isok = 0 ; 
	   for(int i = 1;i <= n;i ++)
	   {
	      scanf("%d",&temp);
		  int k = 10000 - (100-temp) *(100 -temp);
		  if(!hs[k])
			  hsnum ++ ;
		  hs[k] ++; 
		  if(hs[k] >  mx )
		  {
			  mx = hs[k];
		      nummax = 1; 
		  }
		  else if(hs[k] ==  mx)
		  {
		      nummax ++ ;
		  }
	   }
	   if(nummax  == hsnum && hsnum != 1)
	   {
	      printf("Bad Mushroom\n");
		  continue;
	   }
	   int ok = 0 ; 
       for(int i = 0;i <=  10000 ;i ++)
		   if( hs[i] == mx)
		   {
		         if(!ok)
				 {
				    printf("%d",i);
					ok = 1;
				 }else{
				   printf(" %d",i);
				 }
		   }
	   printf("\n");
   }
return 0;
}
