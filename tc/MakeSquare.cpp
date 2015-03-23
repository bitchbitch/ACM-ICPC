// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "MakeSquare.cpp"
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

char str[1000];
int len ; 
int dp[200][200][70];
int solve(int x)
{
  memset(dp,0,sizeof(dp));
  int same = 0 ; 
  for(int i = 1;i <= x ;i ++)
	  for(int j = x+1 ;j <= len ;j ++)
	  {
		  same = 0 ; 
	     if(str[i] == str[j]) 
		 {
		    same = 1;
		 }
		if(same == 0 )
	         for(int k = 0 ; k <= len ; k ++)
			 {
			     dp[i][j][k+1] = max(dp[i][j][k+1],dp[i-1][j-1][k] + 1);
			 }

		   for(int k = 0 ; k <= len; k ++)
			 {
				 dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k] + same);
				 dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k] );
				 dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k] );
			 }
	  }
  int len1 = x;
  int len2 = len - x;
  //printf("%d %d %d\n",len1,len2,dp[x][len]);
  int ans = len;
  for(int k = 0; k <= len; k ++)
  {
    ans = min(ans,len1 - dp[x][len][k] + len2 - dp[x][len][k] + k);
  }
  return ans;
}
class MakeSquare
{
        public:
        int minChanges(string S)
        {
           len = S.size();
		   int ans = len;
		   for(int i = 0 ;i < len; i ++)
			   str[i+1] = S[i];
		   for(int i = 1;i < len;i ++)
			    ans = min(ans,solve(i));
		   return ans;
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abcdabgcd"; int Arg1 = 1; verify_case(0, Arg1, minChanges(Arg0)); }
	void test_case_1() { string Arg0 = "abcdeabce"; int Arg1 = 1; verify_case(1, Arg1, minChanges(Arg0)); }
	void test_case_2() { string Arg0 = "abcdeabxde"; int Arg1 = 1; verify_case(2, Arg1, minChanges(Arg0)); }
	void test_case_3() { string Arg0 = "aabcaabc"; int Arg1 = 0; verify_case(3, Arg1, minChanges(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaabaaaaabaaaaa"; int Arg1 = 2; verify_case(4, Arg1, minChanges(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        MakeSquare ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
