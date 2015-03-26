// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "Suminator.cpp"
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


class Suminator
{
        public:
        int findMissing(vector <int> program, int wantedResult)
        {
        
		     return 1 ;
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(0, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 200, 300, 0, 100, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 600; int Arg2 = 0; verify_case(1, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 7, 3, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 0; verify_case(2, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, 8, 4, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = -1; verify_case(3, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = -1; verify_case(4, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {7, -1, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(5, Arg2, findMissing(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        Suminator ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
