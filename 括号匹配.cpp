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
#include<climits>

using namespace std;
int dp[200][200];
int Min(int a, int b)
{
	if(a < b)
		return a ;
	return b;
}
int main(){

	int t;
	scanf("%d",&t);
	while(t -- ){
	  memset(dp,0,sizeof(dp));
	  char str[200];
	  scanf("%s",str);
	  int n = strlen(str);
	  for(int i = 1;i <= n;i ++)
		  dp[i][i-1] =0 ; 
	  for(int i = 1;i<= n;i++)
		  dp[i][i] = 1; 
      for(int p = 1;p < n;p ++ ){
	      
		  for(int i = 0 ; i < n-p; i ++){
		      int j = i + p;
			  dp[i+1][j+1] = 100000;
			  if((str[i] == '(' && str[j] == ')') || (str[i] == '[' && str[j] == ']'))
			    dp[i+1][j+1] = Min(dp[i+1][j+1],dp[i+2][j]);
			  if(str[i] == '(' || str[i] == '[')
				dp[i+1][j+1] = Min(dp[i+1][j+1],dp[i+2][j+1]+1);
			  if(str[j] == ')' || str[j] == ']')
				dp[i+1][j+1] = Min(dp[i+1][j+1],dp[i+1][j]+1);
			  for(int k = i ;k <= j -1;k ++)
			    dp[i+1][j+1] = Min(dp[i+1][j+1],dp[i+1][k+1]+dp[k+2][j+1]);
		  
		  }
	  
	  }
	  printf("%d\n",dp[1][n]);
	}

	return 0;
}
