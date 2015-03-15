// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "AliceGameEasy.cpp"
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

LL fen(LL x)
{
  LL l = 1, r = 2000000;
  while(l <= r )
  {
    LL m = (l +r )/2;
	LL t = m*(m+1)/2;
	if(t == x)
	{
	   return m ; 
	}else if(t > x){
	   r = m -1;
	}else{
	   l = m + 1; 
	}
  }
  return -1;
}
LL fen2(LL x,LL y)
{
  LL l = 1, r = y;
  LL sum = y*(y + 1)/2;
  while(l <= r)
  {
     LL m = (l + r)/2;
	 LL t = sum - m * (m + 1)/2;
	// printf("%lld %lld\n",m,t);
	 if(t >= x)
	 {
	    l = m + 1;
	 }else {
	    r = m - 1;
	 }
  }
  return y - l +1;
}
class AliceGameEasy
{
        public:
        long long findMinimumValue(long long x, long long y)
        {
			if(x == 0 && y == 0 )
				return 0;
             LL ans = fen(x + y);
			 if(ans == -1)
				 return -1;
			 return fen2(x,ans);
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 0LL; long long Arg2 = 1LL; verify_case(0, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = 0LL; long long Arg2 = 4LL; verify_case(1, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 932599670050LL; long long Arg1 = 67400241741LL; long long Arg2 = 1047062LL; verify_case(2, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 7LL; long long Arg1 = 13LL; long long Arg2 = -1LL; verify_case(3, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 0LL; long long Arg1 = 0LL; long long Arg2 = 0LL; verify_case(4, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_5() { long long Arg0 = 100000LL; long long Arg1 = 400500LL; long long Arg2 = 106LL; verify_case(5, Arg2, findMinimumValue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        AliceGameEasy ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
