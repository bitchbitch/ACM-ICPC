// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "MicroStrings.cpp"
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


class MicroStrings
{
        public:
        string makeMicroString(int A, int D)
        {
                $CARETPOSITION$
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12; int Arg1 = 5; string Arg2 = "1272"; verify_case(0, Arg2, makeMicroString(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "31"; verify_case(1, Arg2, makeMicroString(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 31; int Arg1 = 40; string Arg2 = "31"; verify_case(2, Arg2, makeMicroString(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 30; int Arg1 = 6; string Arg2 = "3024181260"; verify_case(3, Arg2, makeMicroString(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        MicroStrings ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
