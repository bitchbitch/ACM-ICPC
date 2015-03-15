// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "CandleTimerEasy.cpp"
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

int hs[30];
struct node{
  int ne,w;
  node(int _ne ,int _w)
  {
     ne = _ne ; 
	 w = _w; 
  }
};
vector<node> mp[30];
vector<int> leaf;
int ans[41*1000];
int ti[30];
class CandleTimerEasy
{
        public:
        int n ;
	    int sum;	
		void dfs(int k ,int fa , int t)
		{
	//		printf("%d %d %d\n",k,fa,t);
	       	if(t < ti[k])
			{
				ti[k] = t;

			}
			int num = mp[k].size();
			for(int i = 0 ;i < num ;i ++)
			{
			 if(mp[k][i].ne != fa)
			   dfs(mp[k][i].ne,k,t + mp[k][i].w);      
			}
		}
		void solve(vector<int> A,vector<int> B,vector<int> len)
		{
		  int k = leaf.size();
		  int num = (1 << k) -1;
		  //printf("********%d\n",ti[0]);
		  memset(ans,0,sizeof(ans));
		  
		  for(int i = 0 ;i <= num ; i ++)
		  {
		      for(int j = 0 ;j <= n ;j ++)
		      {
		       ti[j] = 1e8;
		      }
			  int hehe = 0 ; 
		      for(int j = 0 ;j < k ;j ++)
			  {
			     if((i >> j ) & 1)
				 {
				//	printf("%d ",leaf[j]);
				    dfs(leaf[j],-1,0);
				    hehe ++ ;
				 }
			  }
			 // puts("");
			  if(hehe == 0 )
				  continue;
			  int mx = 0 ;
			  /*for(int j = 0 ;j <= n;j ++)
				  printf("%d ",ti[j]);
			  printf("\n");
			  */
			  for(int j = 0 ;j < n;j ++)
			  {
				  int tt; 
			      if(abs(ti[A[j]] - ti[B[j]]) < len[j])
				  {
					
				   int  tmi = min(ti[A[j]],ti[B[j]]); 
				   int  tmx = max(ti[A[j]],ti[B[j]]);
				   tt = tmx*2 + (len[j]-(tmx-tmi));
				  }else{
				    tt = min(ti[A[j]],ti[B[j]]) + len[j];
				    tt *= 2;
				  }
			    //  printf("%.1lf ",tt*1.0/2);
				  //printf("%d\n",tt);
				  mx = max(tt,mx);
			  }
			  //printf("***%.1lf\n",mx*1.0/2);
			 // printf("%d\n",mx);
			  if(ans[mx] == 0 )
			  {
				  ans[mx] ++ ;
				  sum ++ ; 
			  }
		  }
		}
		int differentTime(vector <int> A, vector <int> B, vector <int> len)
        {
           n = A.size();
		   sum = 0 ;
		   leaf.clear();
		   memset(hs,0,sizeof(hs));
		   for(int i = 0 ;i <= 20 ;i ++)
			   mp[i].clear();
		   for(int i = 0;i < n; i ++)
		   {
		      mp[A[i]].push_back(node(B[i],len[i]));
		      mp[B[i]].push_back(node(A[i],len[i]));
			  hs[A[i]] ++ ; 
			  hs[B[i]] ++ ; 
		   }

		   for(int i = 0;i <= n;i ++ )
		   {
		      if(hs[i] == 1 )
		        leaf.push_back(i);  		  
		   }
		   solve(A,B,len);
		   return sum;
		}
         
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,1,1,2,3,3,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,3,2,4,6,8,7,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(3, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {123,456,789,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(4, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(5, Arg3, differentTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CandleTimerEasy ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
