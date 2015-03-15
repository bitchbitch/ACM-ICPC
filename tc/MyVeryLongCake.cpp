// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "MyVeryLongCake.cpp"
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


class MyVeryLongCake
{
        public:
        int cut(int n)
        {
		    int  ok = 0 ;
			int ans = 0 ; 
			int t = sqrt(n+1);
            int i ; 
			int max ; 
			for( i = 2;i <= t;i ++)
			{
		         if(n % i == 0 )
				 {
					 
				     max = n / i ;
					 ans = max + max - i ; 
					 ok  = 1 ;
					 break;
				 }
			}
			printf("%d\n",max);
			for(;i <= t;i ++ )
			{
			   if(n % i == 0 )
			   {
			      ans += max -i ; 
				  ans += max - n/i ; 
			   }
			}
			if(ok == 0 )
				return 1; 
			else return ans; 
		
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 4; verify_case(0, Arg1, cut(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; verify_case(1, Arg1, cut(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 7; verify_case(2, Arg1, cut(Arg0)); }
	void test_case_3() { int Arg0 = 1000000000; int Arg1 = 600000000; verify_case(3, Arg1, cut(Arg0)); }
	void test_case_4() { int Arg0 = 577007436; int Arg1 = 384671628; verify_case(4, Arg1, cut(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        MyVeryLongCake ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
