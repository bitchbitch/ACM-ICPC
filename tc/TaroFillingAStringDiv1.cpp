// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "TaroFillingAStringDiv1.cpp"
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
#define M 1000000007
struct node{
  int site; 
  char c;
}a[200];
bool cmp(node a, node b)
{
  return a.site < b.site;
}
LL sum = 0 ; 
void solve(int k , LL dis)
{
	if(dis == 1 || dis == 0 )
		return ;
    if(k)
	{
        if(dis % 2 == 1 )
		{
		  sum = sum *(dis) %M; 
		}
	}else{
        if(dis % 2 == 0)
		{
		  sum = sum *dis %M; 
		}
	
	}
//	printf("%lld\n",sum);
}
class TaroFillingAStringDiv1
{
        public:
        int getNumber(int N, vector <int> site, string str)
        {
		   sum = 1; 
           int n = site.size();
           for(int i = 0;i < n; i ++)
		   {
			   a[i].site = site[i];
		       a[i].c = str[i];
		   }
		   sort(a,a+n,cmp);
           for(int i= 0 ;i < n;i ++)
		   {
			 if(i > 0)
			 if(a[i].c == a[i-1].c)
			 {
			    solve(1,a[i].site - a[i-1].site);
			 }else{
			    solve(0,a[i].site - a[i-1].site);
			 }
		   }
		   return (int)sum;
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AB"; int Arg3 = 2; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {2, 1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABBA"; int Arg3 = 1; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 25; int Arr1[] = {23, 4, 8, 1, 24, 9, 16, 17, 6, 2, 25, 15, 14, 7, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABBBBABABBAAABA"; int Arg3 = 1; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 305; int Arr1[] = {183, 115, 250, 1, 188, 193, 163, 221, 144, 191, 92, 192, 58, 215, 157, 187, 227, 177, 206, 15, 272, 232, 49, 11, 178, 59, 189, 246}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABAABBABBAABABBBBAAAABBABBBA"; int Arg3 = 43068480; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TaroFillingAStringDiv1 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
