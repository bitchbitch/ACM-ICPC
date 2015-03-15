// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "ABC.cpp"
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

int dp[100][100];
int mx[100];
struct node{
  int x; int y;
}mxfrom[100];
void init()
{
	memset(dp,0,sizeof(dp));
    memset(mxfrom,0,sizeof(mxfrom));
    memset(mx,0,sizeof(mx));
	for(int i = 0 ;i <= 30 ;i ++)
		for(int j = 0;j <= 30 - i ;j ++)\
		{
	       dp[i][j] = i * j;
		   for(int s = i + j;s <= 30; s ++)
		   {
		     if(dp[i][j] + (i +j) * (s-(i+j)) > mx[s])
			 {
			   mx[s] = dp[i][j] + (i + j) * (s-(i+j)) ;
			   mxfrom[s].x = i ; 
			   mxfrom[s].y = j ;
			 }
		   }
		}
	   
}
char ans[100];
void insetqian(char A,int n)
{
   int len = strlen(ans);
   for(int i = len - 1;i >= 0 ;i --)
   {
     ans[i+n] =  ans[i];
   }
   for(int i = 0 ;i < n;i ++)
	   ans[i] = A;
}
void insethou(char A,int n)
{
    int len = strlen(ans);
	for(int i = len ;i <= len + n -1;i ++)
		ans[i] = A;
}
void insetzhong(char A,int n)
{
	 int len = strlen(ans);
     for(int i = len - 1;i >= n;i --)
		 ans[i + 1] = ans[i];
	 ans[n] = A;
}
class ABC
{
        public:
        string createString(int N, int K)
        {
            init();
			if(K > mx[N])
				return "";
		    int x = mxfrom[N].x; 
			int y = mxfrom[N].y;
			memset(ans,0,sizeof(ans));
			
			for(int i = 0 ;i < x;i ++)
				ans[i] = 'A';
			int sum = 0 ; 
			int zhong;
			int hou = 0 ; 
			int qian = 0 ;
			for(int i = 1 ;i <= y ;i ++)
			{
				//printf("%d %d %d\n",sum,x,K);
			     if(sum + x < K )
				 {
					 hou ++ ; 
				     sum += x;
				 }else if(sum +x == K )
				 {
					hou ++;
				    qian = y - hou ; 
					insetqian('B',qian);
					insethou('B',hou);
					sum += x;
					break;
				 }else {
				    zhong = K - sum;
					qian =  y - 1 - hou; 
					insetzhong('B',zhong);
					insetqian('B',qian);
					insethou('B',hou);
					sum += zhong;
					break;
				 }
				 if(i == y)
				 insethou('B',hou);
			}
			hou = 0 ; 
			qian = 0 ; 
			for(int i = 1;i <= N - x -y;i ++ )
			{
			     if(sum + (x+y) < K )
				 {
					sum += (x+y);
					hou ++ ; 
				 }
				 else if(sum +(x +y) == K )
				 {
					hou ++ ; 
				    qian = N - x - y - hou ; 
					insethou('C',hou);
					insetqian('C',qian);
					sum += (x+y);
					break;
				 }else {
				    zhong = K - sum;
					qian =  N - x - y - 1 - hou; 
					insetzhong('C',zhong);
					insetqian('C',qian);
					insethou('C',hou);
					sum +=zhong;
					break;
				 }
				 if(i == N-x-y)
				 insethou('C',hou);
			}
		   string rans ;
		   rans.clear();
		   int len = strlen(ans);
		
		   for(int i = 0 ;i < len ;i ++ )
			   rans.push_back(ans[i]);
		   return rans;
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; string Arg2 = "ABC"; verify_case(0, Arg2, createString(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 0; string Arg2 = "CBA"; verify_case(1, Arg2, createString(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 10; string Arg2 = ""; verify_case(2, Arg2, createString(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 36; string Arg2 = "CABBACCBAABCBBB"; verify_case(3, Arg2, createString(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ABC ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
