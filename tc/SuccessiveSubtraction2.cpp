// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "SuccessiveSubtraction2.cpp"
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
#define maxn 2005
int ary[maxn];
int n;
int dp[maxn][6];
int solve()
{
	int ans = -1e9; 
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= n;i ++)
		for(int j = 0 ;j <= 4; j ++)
			dp[i][j] = -1e9;
	dp[1][0] = ary[1];
	dp[2][0] = ary[1]-ary[2];
	for(int i = 3 ;i <= n;i ++)
	{
		dp[i][0] = dp[i-1][0] - ary[i] ;
        dp[i][1] = max(dp[i-1][1]+ary[i],dp[i-1][0]+ary[i]);
        dp[i][2] = max(dp[i-1][2]-ary[i],dp[i-1][1]-ary[i]);
        dp[i][3] = max(dp[i-1][3]+ary[i],dp[i-1][2]+ary[i]);
        dp[i][4] = max(dp[i-1][4]-ary[i],dp[i-1][3]-ary[i]);
	}
	for(int i= 0 ;i <= 4;i ++)
	{
       ans = max(ans,dp[n][i])	;
	}
	return ans ;
}
class SuccessiveSubtraction2
{
        public:
        vector <int> calc(vector <int> a, vector <int> p, vector <int> v)
        {
           vector<int> ans ;    
           n = a.size();
		   int sum =0 ;
		   for(int i =0 ;i < n ;i ++)
		   {
			   ary[i+1] =a[i];
		   }
		   int k = p.size(); 
		   for(int i =0 ;i < k ;i ++)
		   {
		      ary[p[i]+1] = v[i];
			  ans.push_back(solve());
		   }
		   return ans ;
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 0, 4, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 9, -10, 5, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10, 16, 5, 5, 2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-100, -100, -100, -100, -100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0, 0, 0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {400, 300, 200, 100, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {83, 0, 25, 21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 2, 1, 3, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, -90, 33, 52, -100, 0, 45}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {56, 125, 133, 81, 91, 143, 155 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, -10, 100, -100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10, -10, 100, -100 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {-11, -4, 28, 38, 21, -29, -45, 11, -58, -39, 92, 35, -56, -6, 29, -2, 61, 10, -29, -63}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {19, 5, 3, 10, 4, 18, 5, 2, 0, 15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-19, 21, 7, -66, 38, -39, -22, 24, -32, 13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {451, 443, 412, 440, 457, 467, 468, 464, 443, 458 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, calc(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        SuccessiveSubtraction2 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
