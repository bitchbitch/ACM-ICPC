// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "ThePermutationGame.cpp"
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
#define maxn 1000005
#define M 1000000007
int hs[maxn];
int a[maxn];
int t = 0 ; 
int solve()
{
   for(int i = 2;i <= sqrt(100000);i ++)
   {
      if(hs[i] == 0)
	  {
	     int k = i * i ; 
		 while(k <= 100000)
		 {
		    hs[k] = 1;
			k = k + i ; 
		 }
	  }
   }
   for(int i = 2;i <= 100000;i ++)
   {
      if(hs[i] == 0 )
	  {
	     t ++;
		 a[t] = i ; 
	  }
   }

}
int ans[10000];
int tmp[10000];
LL P(LL x,LL y)
{
  if(y == 0 )
	  return 1;
  LL ttt = P(x,y/2);
  if(y%2 == 0 )
	  return ttt*ttt % M;
  else return ((ttt*ttt)%M)*x%M;
}
class ThePermutationGame
{
        public:
        int findMin(int N)
        {
		  memset(hs,0,sizeof(hs));
		  t = 0 ; 
		  solve();
		  printf("%d\n",t);
          for(int i = 1;i <= N;i++)
		  {
			 memset(tmp,0,sizeof(tmp));
			 int k = i ;
			 int tt = 1 ;
		     while(k!=1)
			 {
			    if(k %a[tt] == 0 )
				{
				  k = k/a[tt];
				  tmp[tt] ++ ; 
				}else{
				   tt ++ ; 
				}
			 }
			 for(int j = 1; j <= tt;j ++)
			 {
			   ans[j] = max(ans[j],tmp[j]);
			 }
		  }
		  LL sum = 1; 
		  for(int j = 1;j <= t; j ++)
		  {
		     sum = sum * P(a[j],ans[j]) % M;
		  }
		  return sum; 
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, findMin(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 6; verify_case(1, Arg1, findMin(Arg0)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 504; verify_case(2, Arg1, findMin(Arg0)); }
	void test_case_3() { int Arg0 = 102; int Arg1 = 841777601; verify_case(3, Arg1, findMin(Arg0)); }
	void test_case_4() { int Arg0 = 9999; int Arg1 = 804862568; verify_case(4, Arg1, findMin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ThePermutationGame ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
