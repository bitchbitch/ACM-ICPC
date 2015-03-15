// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "SquareDivisor.cpp"
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


class SquareDivisor
{
        public:
        long long biggest(long long n)
        {      
			 LL maxn = 1;
			 if(1ll*LL(sqrt(n))*LL(sqrt(n)) == n)
				 return n;
	         for(LL i = 1;i <= sqrt(n+1) ; i++)
			 {
			    LL t = i *i ; 
	//			printf("%lld\n",i);
				if(n % t ==  0 )
				{
				   maxn  = max(maxn,t);
				}
				t = n/(n/t);
				i = sqrt(t);
			 }
			 return maxn;
		} 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 12LL; long long Arg1 = 4LL; verify_case(0, Arg1, biggest(Arg0)); }
	void test_case_1() { long long Arg0 = 100LL; long long Arg1 = 100LL; verify_case(1, Arg1, biggest(Arg0)); }
	void test_case_2() { long long Arg0 = 2014LL; long long Arg1 = 1LL; verify_case(2, Arg1, biggest(Arg0)); }
	void test_case_3() { long long Arg0 = 999999875021574338LL; long long Arg1 = 499999937510787169LL; verify_case(3, Arg1, biggest(Arg0)); }
	void test_case_4() { long long Arg0 = 999999998000000002LL; long long Arg1 = 1LL; verify_case(4, Arg1, biggest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        SquareDivisor ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
