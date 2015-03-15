// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "ErasingCharacters.cpp"
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


class ErasingCharacters
{
        public:
        string simulate(string s)
        {
                $CARETPOSITION$
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cieeilll"; string Arg1 = "cl"; verify_case(0, Arg1, simulate(Arg0)); }
	void test_case_1() { string Arg0 = "topcoder"; string Arg1 = "topcoder"; verify_case(1, Arg1, simulate(Arg0)); }
	void test_case_2() { string Arg0 = "abcdefghijklmnopqrstuvwxyyxwvutsrqponmlkjihgfedcba"; string Arg1 = ""; verify_case(2, Arg1, simulate(Arg0)); }
	void test_case_3() { string Arg0 = "bacaabaccbaaccabbcabbacabcbba"; string Arg1 = "bacbaca"; verify_case(3, Arg1, simulate(Arg0)); }
	void test_case_4() { string Arg0 = "eel"; string Arg1 = "l"; verify_case(4, Arg1, simulate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ErasingCharacters ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
