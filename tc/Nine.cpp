// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "Nine.cpp"
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
#define M 1000000007

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int maxn = 9*9*9*9*9;
int dp2[5005][10];
int pow9[6];
int dp[maxn][32];
void get_nx()
{
    for(int i = 0;i < maxn; i ++){
	    for(int j = 0 ;j <= 9 ;j ++){	
			for(int s = 0 ;s <= 31 ;s ++)
			{
				int ns = 0 ; 
			    for(int t = 0 ;t < 5;t ++){
				     if((1 <<t) & s){
						ns += ((i/pow9[t] + j)% 9)*pow9[t];
					 }else{
						ns += ((i/pow9[t])%9) *pow9[t];
					 }
				}
				nx[i][j][s] = ns;
			}
		}
	}
}
class Nine
{
        public:
        int count(int m, vector <int> d){
			int n = d.size();
			pow9[0] =1; 
			memset(dp,0,sizeof(dp));
			for(int i = 1;i <= 5;i ++)
				pow9[i] = pow9[i-1] * 9 ; 
			memset(nx,-1,sizeof(nx));
		    get_nx();			
			int t = 0 ; 
			dp[0][0] = 1; 
			for(int i = 0 ;i < n ;i ++){
				for(int j = 0 ;j < pow9[m];j ++){
					for(int p = 0 ;p <= 9 ;p ++){
						 dp[!t][nx[j][p][d[i]]] = (dp[!t][nx[j][p][d[i]]] + dp[t][j]) % M;
					}
				}
				memset(dp[t],0,sizeof(dp[t]));
				t = !t; 
			}
			return dp[t][0];
        }
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {1,3,5,8,24,22,25,21,30,2,4,0,6,7,9,11,14,13,12,15,18,17,16,19,26,29,31,28,27,10,20,23}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 450877328; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {31,31,31,31,31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11112; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        Nine ___test;
	    clock_t be,en;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
