// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "NoRightTurn.cpp"
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


class NoRightTurn
{
        public:
        vector <int> countWays(vector <int> x, vector <int> y)
        {
                $CARETPOSITION$
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {-10, 0, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, -10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,-3,-3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,1,-3,3,-3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 5, 1, 1, 1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {14,13,12,11,10,9,8,7,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,4,9,16,25,36,49,64,81,100,121,144,169,196}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 2,-2, 4,-4, 2,-2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 2, 4, 4, 6, 6, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 1, 1, 1, 1, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,-10,-20,10,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-10,-20,10,20,10,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 1, 5, 1, 5, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, countWays(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {222,269,91,114,-355,-241,-61,134,-146,-245,-158,289,230,-247,140,-301,
-125,-9,334,-21,-277,-336,-925,-81,388,-130,-96,327,-71,-327,-383,-214,
-299,199,-221,-240,202,-331,823,385,-165,247,50,-935,177,83,-290,-373,
173,-264,-231,-304,119,-307,-297,-243,396,-339,98,87,56,-43,142,-375,
-190,105,-135,188,34,227,24,56,249,390,-258,61,-216,-16,-79,-37,-345,
-135,332,-189,-334,-386}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-125,67,99,-349,-273,8,-145,182,110,-260,-71,79,-312,-224,-50,288,82,
-6,248,44,39,121,-965,-202,9,-289,-236,340,-265,245,-294,253,-65,-338,
-381,210,-183,205,0,-70,349,-308,-142,915,15,-121,3,346,-136,146,-238,
-304,-44,64,-202,-213,-98,15,-197,225,-355,268,-30,-178,313,-375,96,264,
-384,166,294,21,-317,250,24,374,26,-299,303,92,-43,-33,132,-57,165,-297}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {77, 153, 93, 19, 48, 370, 39, 63, 63, 41, 261, 69, 20, 75, 71, 21, 127, 158, 29, 237, 196, 89, 1, 300, 17, 23, 111, 1, 64, 20, 23, 73, 29, 7, 16, 45, 81, 21, 1, 46, 30, 9, 57, 1, 166, 61, 61, 8, 41, 172, 153, 30, 225, 56, 34, 177, 5, 28, 63, 69, 57, 271, 302, 14, 32, 10, 146, 39, 6, 43, 30, 275, 1, 9, 315, 13, 134, 56, 71, 103, 36, 50, 13, 195, 17, 8 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        NoRightTurn ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
