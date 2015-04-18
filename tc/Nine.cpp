
// BEGIN CUT HERE
/*

*/
// END CUT HERE
/*#line 7 "Nine.cpp"
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
	dp2[0][0] = 1 ;
	for(int i = 1;i<= 5000 ;i ++)
		for(int j = 0 ;j <= 9; j ++){
			for(int s = 0 ; s <= 9 ; s ++){
				dp2[i][(j+s) % 9] =  (dp2[i][(j+s) %9] + dp2[i][j]) % M; 
			}
		}
}
class Nine
{
        public:
        int count(int m, vector <int> d){
			memset(dp2,0,sizeof(dp2));
		    get_nx();
			memset(dp,0,sizeof(dp));
			for()
			return dp[1][0];
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
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
class Nine {
public:
  int count(int, vector <int>);
};
 
const int md = 1000000007;
 
inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
 
inline int mul(int a, int b) {
  return (long long)a * b % md;
}
 
int f[33][100010];
int ways[5555][13];
 
int Nine::count(int que, vector <int> d) {
  int ds = d.size();
  for (int i = 0; i <= ds; i++) {
    for (int j = 0; j < 9; j++) {
      ways[i][j] = 0;
    }
  }
  ways[0][0] = 1;
  for (int i = 0; i < ds; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= 9; k++) {
        int new_j = (j + k) % 9;
        add(ways[i + 1][new_j], ways[i][j]);
      }
    }
  }//预处理 多少位 余数为多少的情况数
  int n = (1 << que);
  vector <int> cnt(n, 0);
  for (int i = 0; i < ds; i++) {
    cnt[d[i]]++;
  }
  int MAX = 1;
  for (int i = 0; i < que; i++) {
    MAX *= 9;
  }
  for (int t = 0; t <= n; t++) {
    for (int z = 0; z < MAX; z++) {
      f[t][z] = 0;
    }
  }
  f[0][0] = 1;
  int cur[42];
  for (int t = 0; t < n; t++) {
    for (int z = 0; z < MAX; z++) {//max代表5个问题的情况压缩
      int zz = z;
      for (int i = 0; i < que; i++) {
        cur[i] = zz % 9;
        zz /= 9;
      }//cur[i] 代表的是每一种状态的余数 

      for (int now = 0; now <= 9; now++) { //枚举位数

        int new_z = 0;
        for (int i = que - 1; i >= 0; i--) {//que代表的是问题个数
          new_z *= 9;
          int digit = cur[i];
          if (t & (1 << i)) {
            digit += now;
            if (digit >= 9) digit -= 9;
          }
		  //
          new_z += digit;
        }
        add(f[t + 1][new_z], mul(f[t][z], ways[cnt[t]][now]));
      }
    }
  }
  return f[n][0];
}
 
