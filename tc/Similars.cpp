// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "Similars.cpp"
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

map <LL,int > mp;
map <LL,int >::iterator ti,tj;
int hs[11];

int pp(LL a,LL b)
{
   int ans = 0 ; 
   while(a && b)
   {
       if(a&b&1 == 1 )
	   {
	      ans ++ ; 
	   }
	   a = a >> 1; 
	   b = b >> 1; 
   }
   return ans;
}
void change(int L)
{
  memset(hs,0,sizeof(hs));
  int t = 0 ; 
  while(L)
  {
    hs[L % 10] = 1; 
    L/= 10 ; 
  }
  LL tmp = 0 ; 
  for(int i = 0 ;i <= 9;i ++)
  {
     if(hs[i])
		 tmp += (1<<i);
  }
  //printf("%lld\n",tmp);
  mp[tmp] ++;
}
class Similars
{
        public:
        int maxsim(int L, int R)
        {
			mp.clear();
			int ans = 0 ;
             for(int i = L ;i <= R ;i ++)
			 {
			    change(i);
			 }
			 for(ti = mp.begin();ti != mp.end();ti++)
				 for(tj = ti ;tj != mp.end();tj++)
				 {
					 if(ti == tj)
					 {
					    if(ti->second >= 2)
						{
						   ans = max(ans,pp(ti->first,tj->first));
						}
					 }else{
						   ans = max(ans,pp(ti->first,tj->first));
					 }
				 }
			 return ans ;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 1; verify_case(0, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 99; int Arg2 = 2; verify_case(1, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 99; int Arg1 = 100; int Arg2 = 0; verify_case(2, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1010; int Arg2 = 2; verify_case(3, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 444; int Arg1 = 454; int Arg2 = 2; verify_case(4, Arg2, maxsim(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        Similars ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
