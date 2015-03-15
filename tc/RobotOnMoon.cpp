// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "RobotOnMoon.cpp"
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

int n , m,x, y;
int solve(int x,int y,vector<string> board)
{
  int mx = 0 ; 
  int ok = 0 ; 
  for(int i = x;i >= 0 ;i --)
  {
     if(board[i][y] == '#') 
	 {
	   ok = 1; 
	 } 
  }
  mx = max(x-0,n-x-1);
  mx = max(mx,y-0);
  mx = max(mx,m-y-1);
  for(int i = x;i < n;i ++)
  {
     if(board[i][y] == '#') 
	 {
	   ok = 1; 
	 } 
  }
  for(int j = y;j >= 0;j --)
  {
     if(board[x][j] == '#') 
	 {
	   ok = 1; 
	 } 
  }
  for(int j = y;j < m;j ++)
  {
     if(board[x][j] == '#') 
	 {
	   ok = 1; 
	 } 
  }
  //printf("%d %d\n",n,m);
  if(ok == 1 )
	  return -1;
  return mx;
  
}
class RobotOnMoon
{
        public:
        int longestSafeCommand(vector <string> board)
        {
             n = board.size();
			 m = board[0].size();
			 for(int i = 0 ;i < n;i ++)
				 for(int j = 0 ;j < m;j ++)
				 {
				    if(board[i][j] == 'S') 
						return solve(i,j,board);
				 }
			 return 0 ;
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(0, Arg1, longestSafeCommand(Arg0)); }
	void test_case_1() { string Arr0[] = {"S......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, longestSafeCommand(Arg0)); }
	void test_case_2() { string Arr0[] = {"#.######",
 "#.#..S.#",
 "#.#.##.#",
 "#......#",
 "########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, longestSafeCommand(Arg0)); }
	void test_case_3() { string Arr0[] = {"S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, longestSafeCommand(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        RobotOnMoon ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
