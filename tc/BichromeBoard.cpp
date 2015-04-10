// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "BichromeBoard.cpp"
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

int ok = 0 ; 

class BichromeBoard
{
        public:
        string ableToDraw(vector <string> str)
        {
		    int n = str.size();
			int m = str[0].size();
			int st = 0 ; 
			int ok = 1 ; 
			for(int i = 0 ;i < n ; i ++)
				for(int j = 0 ;j < m;j ++)
				{	
					if(str[i][j] != '?'){
						if(str[i][j] == 'B')
						{
						   st = (i + j) % 2;
						   for(int i = 0;i < n;i ++)
						   {
						      for(int j = 0 ;j < m;j ++)
							  {
							    if(str[i][j] == 'W'  && (i + j) % 2 == st)
									ok = 0 ; 
							    if(str[i][j] == 'B'  && (i + j) % 2 != st)
									ok = 0  ; 
							  }
						   }
						}else{
						   st = (i + j) % 2;
						   for(int i = 0;i < n;i ++)
						   {
						      for(int j = 0 ;j < m;j ++)
							  {
							    if(str[i][j] == 'B'  && (i + j) % 2 == st)
									ok = 0 ; 
							    if(str[i][j] == 'W'  && (i + j) % 2 != st)
									ok = 0 ; 
							  }
						   }
						}
						break;
					}
				}
			if(ok)
				return "Possible";
			else return "Impossible";
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"W?W",
 "??B",
 "???"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(0, Arg1, ableToDraw(Arg0)); }
	void test_case_1() { string Arr0[] = {"W??W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(1, Arg1, ableToDraw(Arg0)); }
	void test_case_2() { string Arr0[] = {"??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(2, Arg1, ableToDraw(Arg0)); }
	void test_case_3() { string Arr0[] = {"W???",
 "??B?",
 "W???",
 "???W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(3, Arg1, ableToDraw(Arg0)); }
	void test_case_4() { string Arr0[] = {"W???",
 "??B?",
 "W???",
 "?B?W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(4, Arg1, ableToDraw(Arg0)); }
	void test_case_5() { string Arr0[] = {"B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(5, Arg1, ableToDraw(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        BichromeBoard ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
