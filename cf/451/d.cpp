// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年07月25日 星期五 00时31分33秒

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
#define LL long long 
using namespace std;
char str[100005];
int sum[100005];
LL pike2(LL x)
{
   return x*(x-1)/2;
}
int main(){
    scanf("%s",str);
    int len = strlen(str);
    int t= 0;
	int p = 0 ;
	for(int i =1 ;i < len ;i ++)
	{
        if(str[i] != str[i-1])
         {
		    t ++ ; 
			sum[t] = i-p;
            p = i;    
		 }	    
	}
	t ++ ; 
	sum[t] = len -p ;
	LL sume ,sumo;
	sume = sumo = 0 ;
    LL sumek[3];
	LL sumok[3];
	LL ans = 1ll*len*(len+1)/2;
	LL tsum = 0 ;
	memset(sumek,0,sizeof(sumek));
	memset(sumok,0,sizeof(sumok));
	for(int i =1;i <= t ;i ++)
	{
	    if(i % 2 == 1)
		{
	      sumo += sum[i];
		  if(sum[i] % 2 == 0 )
		  {
		      sumok[1] += sum[i]/2;
			  sumok[2] += sum[i]/2;
		  }else{
		     if((tsum+1)%2 == 1)
			 {
			    sumok[1] += sum[i]/2+1;
				sumok[2] += sum[i]/2;
			 }else{
			     sumok[1] += sum[i]/2;
				 sumok[2] += sum[i]/2+1;
			 }
		  }
		   
		}else {
		  if(sum[i] % 2 == 0 )
		  {
		      sumek[1] += sum[i]/2;
			  sumek[2] += sum[i]/2;
		  }else{
		     if((tsum+1)%2 == 1)
			 {
			    sumek[1] += sum[i]/2+1;
				sumek[2] += sum[i]/2;
			 }else{
			     sumek[1] += sum[i]/2;
				 sumek[2] += sum[i]/2+1;
			 }
		  }
		  sume += sum[i] ; 
		}
		tsum += sum[i];
	}
//	printf("%lld %lld %lld %lld\n",sumok[1],sumok[2],sumek[1],sumek[2]);
	ans = ans - sumo*sume;
    LL temp = pike2(sumek[1])+pike2(sumek[2])+pike2(sumok[1]) + pike2(sumok[2])+sumo+sume;
    printf("%lld %lld\n",ans-temp,temp); 
return 0;
}
