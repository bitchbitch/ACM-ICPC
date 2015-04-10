// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "FoldingPaper2.cpp"
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

int find(int now,int val)
{
	if(now == val)
		return 0 ; 
    if(val > now/2)
		return 1;
	if(now % 2 == 0 )
		return 1 + find(now/2,val);
	return 1 + find(now/2+1,val);
}
class FoldingPaper2
{
        public:
        int solve(int W,int  H, int A)
        {
			int mi = 1e9; 
			int ok = 0 ; 
			for(int i = 1; i <= sqrt(A) + 1;i ++)
			{
				if(A % i == 0 )
				{
				  if(i <= W && A/i <= H)
				  {
				  mi = min(find(W,i)+find(H,A/i),mi);
				  ok = 1; 
				  }
				  if(i <= H && A/i <= W)
				  {
				  mi = min(find(H,i)+find(W,A/i),mi);
				  ok = 1; 
				  }
				}
			}
			if(ok)
			return mi ;
			else return -1; 

        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 12; int Arg3 = 1; verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 3; int Arg3 = -1; verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; int Arg3 = 4; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 127; int Arg1 = 129; int Arg2 = 72; int Arg3 = 8; verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 100000; int Arg2 = 100000; int Arg3 = 0; verify_case(4, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; int Arg3 = -1; verify_case(5, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        FoldingPaper2 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
