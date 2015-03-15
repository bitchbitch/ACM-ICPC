// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年10月03日 星期五 12时15分11秒

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
int n;
int lstr;
int lstr1;
char str1[1005];
char str[1005];
int fx[1005];
int dp[1005][1005];
void change()
{
	for(int i = 0 ;i < lstr1 ;i ++)
	{
		if(str1[i] >= 'a' && str1[i] <= 'z')
		{
			fx[lstr] = i;
			str[lstr++]  = str1[i];

		}
		else if(str1[i] >= 'A' && str1[i] <= 'Z')
		{
			fx[lstr] = i;
			str[lstr++] = str1[i] -'A' + 'a'; 
		}
	}
}
int ansb = 0; 
int ansl = 0;
void solve()
{
	//puts(str);
	for(int i = 0 ;i < lstr ; i ++)
	{
		dp[i][1] = 0 ; 
	}
	for(int i = 1;i < lstr;i ++)
	{
		if(str[i] == str[i-1]) 
		{
			dp[i][2] = 0;  
		}else if(1 <= 2*n){
			dp[i][2] = 2; 
		}
		for(int j = 1;j <= i ;j ++)
		{
			if(dp[i-1][j] != -1)
			{
				if(fx[i-1] - fx[i-j] + 1> ansl)
				{
					ansl = fx[i-1] -fx[i-j] + 1 ; 
					ansb = fx[i-j] +1;
				}
				if(i-1-j >= 0 )
				{
					if(str[i] == str[i-1-j]) 
					{
						dp[i][j+2] = dp[i-1][j];
					}else if(dp[i-1][j] + 1 <= 2 * n){
						dp[i][j+2] = dp[i-1][j] + 2; 
					}
				}
			}
		}
	}
	for(int i = 1;i <= lstr;i ++)
	{
		if(dp[lstr-1][i] != -1 && fx[lstr-1] - fx[lstr-i] +1  > ansl )
		{
			ansl = fx[lstr-1] - fx[lstr-i] + 1;
			ansb = fx[lstr-i] + 1;
		}
	}
/*	for(int i = 0;i < lstr;i ++)
	{
		for(int j = 1;j <= i+1;j ++)
		{
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}*/

}
int main(){
	int ca = 0 ; 
	while(scanf("%d",&n) != EOF)
	{
		getchar();
		ca ++ ;
		memset(dp,-1,sizeof(dp));
		memset(str,0,sizeof(str));
		gets(str1);
		lstr1 = strlen(str1);
		lstr = 0 ; 
		change(); 
		ansb = 1; 
		ansl = 1; 
		solve();
		printf("Case %d: %d %d\n",ca,ansl,ansb);
	}

	return 0;
}
