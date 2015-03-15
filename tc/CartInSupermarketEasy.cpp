// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "CartInSupermarketEasy.cpp"
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

int dp[104][104];
void init(int N,int K)
{
  for(int i = 0 ;i<= 100 ;i ++)
	  dp[1][i] = 1; 
  for(int i = 2;i <= N ;i ++)
      {
        dp[i][0] = i ; 
	    for(int j = 1;j <= K;j ++)
	    {
			dp[i][j] = dp[i][j-1];
	        for(int s = 1;s < i; s++)
			{
			  for(int ij = 0;ij <  j; ij++)
			  {
			    dp[i][j] = min(dp[i][j],max(dp[s][ij] ,dp[i-s][j-ij-1])+1);
			  }
			}
		}
	  }
}
class CartInSupermarketEasy
{
        public:
        int calc(int N, int K)
        {
			memset(dp,0,sizeof(dp));
			init(N,K);
		    return dp[N][K];
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 5; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 4; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 4; int Arg2 = 6; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 100; int Arg2 = 4; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 45; int Arg1 = 5; int Arg2 = 11; verify_case(4, Arg2, calc(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 8; verify_case(5, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CartInSupermarketEasy ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
