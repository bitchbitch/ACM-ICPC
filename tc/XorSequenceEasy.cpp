// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "XorSequenceEasy.cpp"
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

struct node{
  int x, y;
  node()
	{};
  node(int _x,int _y)
  {
    x = _x; 
	y = _y;
  }
};
int p[31];
int count1(vector<int>A,int k)
{
   int len = A.size();; 
   int sum = 0 ; 
   for(int i = 0 ;i < len ;i ++)
   {
     for(int j = i+1;j < len ;j ++)
	 {
	   if((A[i]/p[k-1])%10 < (A[j]/p[k-1])%10)
		   sum ++ ; 
	 }
   }
   return sum ; 
}
int count2(vector<int>A,int k)
{
   int len = A.size();; 
   int sum = 0 ; 
   for(int i = 0 ;i < len ;i ++)
   {
     for(int j = i+1;j < len ;j ++)
	 {
	   if((A[i]/p[k-1])%10 > (A[j]/p[k-1])%10)
		   sum ++ ; 
	 }
   }
   return sum ; 
}
int ans[40][3];
void solve(vector<int> A,int k)
{
	if(A.size() == 0 )
	   return ;
	if(k == 0)
	   return;
	vector<int>B;
	vector<int>C;
    int len = A.size();
	ans[k][1] += count1(A,k);
	ans[k][2] += count2(A,k);
	for(int i = 0 ;i < len ;i++)
	{
	   if((A[i]/p[k-1])%2)
		   B.push_back(A[i]);
	   else C.push_back(A[i]);
	}
	solve(B,k-1);
	solve(C,k-1);
}
class XorSequenceEasy
{
        public:
        int getmax(vector <int> A, int N)
        {
		    p[0] = 1;
		   for(int i = 1;i <= 30;i ++)
			   p[i] = p[i-1] * 2; 
		   memset(ans,0,sizeof(ans));
           solve(A,30);
		   int rans = 0 ; 
		   for(int i = 0 ;i <= 39;i ++)
		   {
			   rans += max(ans[i][1],ans[i][2]);
//		      printf("%d\n",rans);
		   }
		   return rans;
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,2,1,0,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 8; verify_case(0, Arg2, getmax(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,0,4,6,1,5,7,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 21; verify_case(1, Arg2, getmax(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = 76; verify_case(2, Arg2, getmax(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 0; verify_case(3, Arg2, getmax(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {408024109,11635919,196474438,117649705,812669700,553475508,445349752,271145432,730417256,738416295
,147699711,880268351,816031019,686078705,1032012284,182546393,875376506,220137366,906190345,16216108
,799485093,715669847,413196148,122291044,777206980,68706223,769896725,212567592,809746340,964776169
,928126551,228208603,918774366,352800800,849040635,941604920,326686120,920977486,964528038,659998484
,207195539,607901477,725914710,655525412,949610052,142750431,766838105,1024818573,836758851,97228667}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1073741824; int Arg2 = 720; verify_case(4, Arg2, getmax(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        XorSequenceEasy ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
