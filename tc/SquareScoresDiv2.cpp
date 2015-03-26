// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "SquareScoresDiv2.cpp"
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


class SquareScoresDiv2
{
        public:
        int getscore(string s)
        {
           int t = 1 ; 
		   int sum = 0 ; 
		   int len = s.size();
		   for(int i = 1 ;i < s.size(); i ++)
		   {
		        if(s[i] != s[i-1])
				{
				  int tsum = 0 ; 
			       for(int j = 1; j <= t; j ++ )
				   {
				     tsum += j ;
				   }
				   sum += tsum  ;
				   t = 1 ;
				}else{
				  t ++ ; 
				}
		   }
		   int tsum = 0 ; 
		   for(int j = 1; j <= t ;j ++)
		   {
		    tsum += j ; 
		   }
		   return sum + tsum ; 
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaaba"; int Arg1 = 8; verify_case(0, Arg1, getscore(Arg0)); }
	void test_case_1() { string Arg0 = "zzzxxzz"; int Arg1 = 12; verify_case(1, Arg1, getscore(Arg0)); }
	void test_case_2() { string Arg0 = "abcdefghijklmnopqrstuvwxyz"; int Arg1 = 26; verify_case(2, Arg1, getscore(Arg0)); }
	void test_case_3() { string Arg0 = "p"; int Arg1 = 1; verify_case(3, Arg1, getscore(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; int Arg1 = 5050; verify_case(4, Arg1, getscore(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        SquareScoresDiv2 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
