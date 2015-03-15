// File Name: c.cpp
// Author: darkdream
// Created Time: 2013年12月24日 星期二 22时21分05秒

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
int a[5] = {1,8,6,9};
int hs[10];
int ans[10][5];
int hss[10];
char str[1000005];
int main(){
    memset(hs,0,sizeof(hs));
	memset(hss,0,sizeof(hss));
    do
	{
	  for(int i = 0; i <= 6;i ++ )
	  {
		int temp = a[3] + a[2] * 10  + a[1] * 100 + a[0]*1000 + i * 10000;
	    if(temp % 7 == 0 && !hs[i] )
		{
			hs[i] = 1;
			for(int j= 0 ; j<= 3; j ++)
			{
			  ans[i][j] = a[j];
			}
		}
	  }
	}while(next_permutation(a,a+4));
	scanf("%s",str);
    int len = strlen(str);
	int  k = 0 ; 
	for(int i = 0 ;i < len ;i ++)
	{
	  int temp =  str[i] -'0'; 
	  if(temp == 1||temp == 6 || temp == 8 || temp == 9 )
	  {
	     if(!hss[temp])
		 {
		  hss[temp] = 1;
		 }else {
			 printf("%d",temp);
		   k = (k * 10 + temp)%7;
		 }
	  }else if(temp == 0 )
	  {
	    hss[0] ++ ; 
	  }else {
		 printf("%d",temp);
		 k = (k * 10 + temp)%7;
	  }
	}
	for(int i = 0 ;i <= 3; i++)
		printf("%d",ans[k][i]);
	for(int i = 1 ;i <= hss[0]; i ++)
		printf("0");
	 printf("\n");
    
	
return 0;
}
