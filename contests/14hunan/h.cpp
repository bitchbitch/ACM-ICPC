// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年10月21日 星期二 21时54分34秒

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
#define inf 1000000;
using namespace std;
char str[1004];
int dp[1004][6][6];
void print(int t)
{
  for(int i = 1;i <= 4;i ++)
  {
     for(int j = 1;j <= 4;j ++)
		 printf("%d ",dp[t][i][j]);
	 printf("\n");
  }
  printf("\n");
}
void init(int t)
{
	for(int i = 1;i <= 4 ;i ++)
		for(int j = 1;j <= 4;j ++ )
			if(j == 1 || j == 3)
			{
				dp[t][i][j] = -inf;
			}else {
				dp[t][i][j] = inf;
			}
}
int main(){
	int ca = 0 ;
	while(scanf("%s",str) != EOF)
	{
		ca ++ ; 
		init(0);
		for(int i = 1;i <= 4;i ++)
			dp[0][1][i] = 0 ;
		int len = strlen(str);
		int t = 0 ;
		//print(0);
		for(int i = 0 ;i < len ;i ++)
		{
			if(str[i] == 'R')
			{
				for(int j = 1 ; j <= 4;j ++)
					memcpy(dp[t][j-1],dp[t][j],sizeof(dp[0][0]));
				memcpy(dp[t][4],dp[t][0],sizeof(dp[0][0]));
			}else if(str[i] == 'L'){
				for(int j = 4 ; j >= 1;j --)
					memcpy(dp[t][j+1],dp[t][j],sizeof(dp[0][0]));
				memcpy(dp[t][1],dp[t][5],sizeof(dp[0][0]));
			}else if(str[i] == 'F'){
				for(int j = 1;j <= 4;j ++)
				{
					if(j == 1)
					{
						dp[t][j][1] ++; 
						dp[t][j][2] ++;
					}else if(j == 2)
					{
						dp[t][j][3] ++; 
						dp[t][j][4] ++;
					}else if(j == 3)
					{
						dp[t][j][1] --; 
						dp[t][j][2] --;
					}else {
						dp[t][j][3] --; 
						dp[t][j][4] --;
					}
				}
			}else{
				t ++ ; 
				init(t);
				int s1,s;
				for(int j = 1;j <= 4 ;j ++)
				{
					int ne = (j == 4 ? 1:j + 1) ;
					for(s = 1 ,s1 = 2; s <= 4l; s += 2, s1 += 2)
					{
						if(dp[t-1][j][s] > dp[t][ne][s])
						{
							dp[t][ne][s] = dp[t-1][j][s];
						}
						if(dp[t-1][j][s1] <  dp[t][ne][s1])
						{
							dp[t][ne][s1] = dp[t-1][j][s1];
						}
					}
					ne = (j == 1 ? 4:j - 1);
					for(s = 1 ,s1 = 2; s <= 4; s += 2, s1 += 2)
					{
						if(dp[t-1][j][s] > dp[t][ne][s])
						{
							dp[t][ne][s] = dp[t-1][j][s];
						}
						if(dp[t-1][j][s1] <  dp[t][ne][s1])
						{
							dp[t][ne][s1] = dp[t-1][j][s1];
						}
					}

				}
				for(int j = 1;j <= 4;j ++) 
				{
					if(j == 1)
					{
					    dp[t][j][1] = max(dp[t][j][1],dp[t-1][j][1] + 1);
						dp[t][j][2] = min(dp[t][j][2],dp[t-1][j][2] + 1);
						dp[t][j][3] = max(dp[t][j][3],dp[t-1][j][3] );
						dp[t][j][4] = min(dp[t][j][4],dp[t-1][j][4] );
					}else if(j == 2)
					{
					    dp[t][j][1] = max(dp[t][j][1],dp[t-1][j][1]);
						dp[t][j][2] = min(dp[t][j][2],dp[t-1][j][2]);
						dp[t][j][3] = max(dp[t][j][3],dp[t-1][j][3] + 1);
						dp[t][j][4] = min(dp[t][j][4],dp[t-1][j][4] + 1);
					}else if(j == 3)
					{
						dp[t][j][1] = max(dp[t][j][1],dp[t-1][j][1] - 1);
						dp[t][j][2] = min(dp[t][j][2],dp[t-1][j][2] - 1);
						dp[t][j][3] = max(dp[t][j][3],dp[t-1][j][3] );
						dp[t][j][4] = min(dp[t][j][4],dp[t-1][j][4] );
					}else{
					    dp[t][j][1] = max(dp[t][j][1],dp[t-1][j][1]);
						dp[t][j][2] = min(dp[t][j][2],dp[t-1][j][2]);
						dp[t][j][3] = max(dp[t][j][3],dp[t-1][j][3] - 1);
						dp[t][j][4] = min(dp[t][j][4],dp[t-1][j][4] - 1);
					}
				}
			}
        //print(t);
		}
		int minx ,maxx,miny ,maxy;
		minx = miny = inf;
		maxx = maxy = -inf;
		for(int j = 1;j <= 4;j ++)
		{
			if(dp[t][j][1] > maxx)
				maxx = dp[t][j][1];
			if(dp[t][j][2] < minx)
				minx = dp[t][j][2];
			if(dp[t][j][3] > maxy)
				maxy = dp[t][j][3];
			if(dp[t][j][4] < miny)
				miny = dp[t][j][4];
		}
        printf("Case %d: %d %d %d %d\n",ca,minx,maxx,miny,maxy);
	}
	return 0;
}
