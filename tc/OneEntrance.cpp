// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "OneEntrance.cpp"
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

vector<int >mp[14];
int vis[15];
int ru[15];
int len;
int ans ; 
void dfs(int n )
{
	if(n == len+1)
	{
	   ans ++ ;
	   return;
	}
	for(int tt = 0 ;tt <= len ; tt ++)
	{
		if(!vis[tt]&& ru[tt] == 1 )
		{
		//	printf("***%d  ",tt);
			int k  = -1; 
			for(int i = 0 ;i < mp[tt].size();i ++)
			{
				if(!vis[mp[tt][i]])
				{
					k = mp[tt][i];
		//		    printf("%d ",k);
					break;
				}
			}
			if(k == -1)
			{
			   vis[tt] = 1; 
			   dfs(n+1);
			   vis[tt] = 0 ; 
			   continue;;
			}
			ru[tt]--;
			ru[k] -- ;
			vis[tt] = 1 ; 
			dfs(n+1);
			ru[tt]++;
			ru[k] ++ ;
			vis[tt] = 0 ; 
		}
	}
}
class OneEntrance
{
        public:
        int count(vector <int> a, vector <int> b, int s)
        {
			ans = 0 ; 
			memset(vis,0,sizeof(vis));
            len = a.size();
			if(len == 0)
				return 1; 
			memset(ru,0,sizeof(ru));
			for(int i= 0 ;i <= len + 1;i ++)
				mp[i].clear();
			for(int i = 0 ;i  < len ;i ++)
			{
			    mp[a[i]].push_back(b[i]);
				mp[b[i]].push_back(a[i]);
				ru[a[i]] ++ ; 
				ru[b[i]] ++ ; 
			}
	       vis[s] = 1 ;
		   dfs(1);
		   return ans ; 

		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 3; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 24; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {7, 4, 1, 0, 1, 1, 6, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 6, 2, 5, 0, 3, 8, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 896; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        OneEntrance ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
