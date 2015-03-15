// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "TheGridDivTwo.cpp"
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

map<int,map<int,int> > mp;

int ans;
struct node{
  int x, y ,step;  
  node(){}
  node(int _x,int _y,int _step)
  {
     x= _x; 
	 y = _y ;
	 step = _step;
  }
}que[1000055];
int x[] = {1,-1,0,0};
int y[] = {0,0,1,-1};
int limit;
void bfs()
{
   int l ;
   int r ;
   l = r  = 1;
   que[1] = node(0,0,0);
   while(l <= r )
   {
	   ans = max(que[l].x,ans);
	  // printf("%d %d %d %d\n",que[l].x,que[l].y,limit,que[l].step);
	   if(que[l].step < limit && abs(que[l].y) <= 50)
	   {
		  // printf("***\n");
		   for(int i = 0 ;i <= 3; i ++)
		   {
			   int tx = que[l].x + x[i];
			   int ty = que[l].y + y[i];
			   if(mp[tx][ty] != 1 )
			   {
				   mp[tx][ty] = 1;
				   r ++ ; 
				   que[r] = node(tx,ty,que[l].step + 1);
			   }
		   }
	   }
	  l ++ ; 
   }
   printf("%d\n",r);
}
class TheGridDivTwo
{
	public:
		int find(vector <int> x, vector <int> y, int k)
		{
		//	int en = clock();
			limit = k ; 
			ans = 0;
			int n = x.size();
			mp.clear();
			for(int i = 0 ;i < n;i ++)
			{
				mp[x[i]][y[i]] = 1; 
			}
			bfs();
		//	int be = clock();
		//	printf("%lf\n",(be - en)*1.0/CLOCKS_PER_SEC);
			return ans ; 
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,-1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 2; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-1, 0, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 0; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 1000; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,-1,1,-2,2,-3,3,-4,4,-5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; int Arg3 = 31; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TheGridDivTwo ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
