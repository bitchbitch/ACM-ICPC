// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "Fragile2.cpp"
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

int mp[100][100];
int fa[100];
int n;
int find(int x)
{
   return fa[x] == x?x:fa[x] = find(fa[x]);
}
int count(int x, int y )
{
   int hs[100];
   memset(hs,0,sizeof(hs));
   for(int i = 0 ;i < n;i ++)
	   fa[i] = i ;
   for(int i = 0;i < n;i ++)
   {
	  if(i == x || i == y)
		   continue;
      for(int j = 0; j < n;j ++)
	  {
	    if(j == x || j == y)
		    continue;
	    if(mp[i][j] == 1 )
		{
	       int fx = find(i);
		   int fy = find(j);
		   if(fx != fy)
		   {
		      fa[fy] = fx;
		   }
		}
	  }
   }
   int csum = 0 ; 
   for(int i = 0 ;i < n;i ++)
   {
	  int t = find(i);
      if(!hs[t])
	  {
	     csum ++ ;
		 hs[t] = 1; 
	  }
   }
   return csum - 2;
}
class Fragile2
{
        public:
        int countPairs(vector <string> graph)
        {
		  memset(mp,0,sizeof(mp));
           n = graph.size();
	       for(int i = 0 ;i < n;i ++)
		   {
		      for(int j = 0 ;j < n;j ++)
			  {
			     if(graph[i][j] == 'Y')
				 {
				    mp[i][j] = 1; 
				 }
			  }
		   }
		   int tmp = count(100,100) + 2;
		   int sum = 0 ; 
		   for(int i = 0 ;i < n;i ++)
			   for(int j = i + 1 ;j < n;j ++ )
			   {
			       int k =  count(i,j);
				   if(k > tmp)
					   sum ++;
			   }
		   return sum ; 
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNN", "YNYN", "NYNY", "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, countPairs(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYNNNN", "YNYNNN", "NYNNNN", "NNNNYN", "NNNYNY", "NNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, countPairs(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNN", "NNN", "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countPairs(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNYNNYYNN", "YNNNYNYYNN", "NNNNYNNNYN", "YNNNYYNNNN", "NYYYNNNNYN",
 "NNNYNNNNYN", "YYNNNNNNNN", "YYNNNNNNYN", "NNYNYYNYNY", "NNNNNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, countPairs(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNNYNNYNNNNNNNYYNNNY", "NNNNNNNNYNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNN", "YNNNNNNNNNYNNNNNNNNN", "NNNNNNNYNNNNNYNNNNYN",
 "NNNNNNNNNNNNNNNNYNNY", "YNNNNNNNNNNNNYYYNYNN", "NNNNYNNNNNNNNYYNNNNN", "NYNNNNNNNYNNNNNNNNNN", "NNNNNNNNYNNNYNNNNNYN",
 "NNNYNNNNNNNNNNYNNNNN", "NNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNYNNNNNNNYNN", "NNNNYNYYNNNNNNNNNNNN", "YNNNNNYYNNYNNNNNNNNN",
 "YNNNNNYNNNNNNNNNYNNN", "NNNNNYNNNNNNNNNYNYNN", "NNNNNNYNNNNNYNNNYNNN", "NNNNYNNNNYNNNNNNNNNN", "YNNNNYNNNNNNNNNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; verify_case(4, Arg1, countPairs(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        Fragile2 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
