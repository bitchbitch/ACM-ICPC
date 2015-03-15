// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "FoxConnection2.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
#define MOD 1000000007
int dp[100][100];
int dmap[100][100];
class FoxConnection2
{
        public:
        int ways(vector <int> A, vector <int> B, int k)
        {
		   memset(dmap,0,sizeof(dmap));
		   memset(dp,0,sizeof(dp));
		   int max = 0 ; 
           for(int i = 0 ; i < A.size(); i ++)
		   {
			 if(A[i] > max )
				 max = A[i];
			 if(B[i] > max)
				 max = B[i];
		     dmap[A[i]][B[i]] = 1; 
			 dmap[B[i]][A[i]] = 1; 
		   }
		   for(int i = 0;i <= 50 ;i ++)
              dp[i][1] = 1;
		   int sum = 0 ; 
		   for(int i = 1;i <= 50 ;i ++)
			   for(int j = 1;j < i ;j ++)
			   {
			     if(dmap[i][j])
				 {
				   for(int s = k -1  ;s >= 1  ;s --)
				   {
				      dp[i][s+1] = (dp[i][s+1] + dp[j][s])%MOD;
					  dp[j][s+1] = (dp[j][s+1]+ dp[i][s+1])%MOD;
				      if(s ==  k-1)
					  {

					     sum = (sum + dp[j][s])%MOD;
					  }
				   }
				 }
			   }
		  /* for(int i = 1;i <= 5;i ++)
			{
			  for(int j = 1; j <= 5; j ++)
				  printf("%d ",dp[i][j]);
			  printf("\n");
			}
		   *for(int i= 1;i<= 50 ;i ++)
		   {
		      sum = (sum + dp[i][k]) % MOD;
		   }*/
		   if(k == 1)
		      sum += max;
		   return sum;
        }
}; 
