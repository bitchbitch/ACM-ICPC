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
#include<unistd.h>
#define LL long long
#define M 1000000007
using namespace std;
int dp[1005][1005];

int main(){
	for(int i = 0;i <= 1000 ;i ++)
		dp[i][0] = 1;
	for(int i = 1;i <= 1000;i ++)
		for(int j = 1;j <= 1000;j ++)
		{
		  dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%M;
		}
	printf("%d\n",dp[4][2]);
	return 0;
}
