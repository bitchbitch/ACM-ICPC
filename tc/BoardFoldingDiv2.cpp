// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "BoardFoldingDiv2.cpp"
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
int n , len ;
int sumh = 0 ; 
int suml = 0 ; 
int isok(int l ,int r,int x)
{
	 int m = (l + r)/2;
     for(int i = l ;i <= m;i ++)
	 {
	    for(int j = 1;j <= x;j ++)
		{
	        if(mp[i][j] != mp[r -(i -l)][j])
				 return 0 ;
		}
	 }
	 return 1;
}
int mp1[100][100];
int vis[100][100];
void solve(int l ,int r,int &sum,int x)
{
   if(vis[l][r])
	   return ;
   else{
    sum ++ ;
	vis[l][r] = 1;
	//printf("%d %d\n",l,r);
   }
   for(int i = l + 1;i <= r; i +=2)
   {
       if(isok(l,i,x))
	   {
	     solve((l+i)/2 + 1,r,sum,x);
	   }
   }
   for(int i = r-1;i >= l ;i -= 2)
   {
       if(isok(i,r,x))
	   {
	     solve(l,(i+r)/2,sum,x);
	   }
   }
   
}
void print(int x, int y)
{
  for(int i = 1;i <= x;i ++)
  {
     for(int j = 1;j <= y ;j ++)
		 printf("%d",mp[i][j]);
	 puts("");
  }
}
class BoardFoldingDiv2
{
        public:
        int howMany(vector <string> paper)
        {
		  n = paper.size();
		  len = paper[0].size();
		  for(int i = 0 ;i < n;i ++)
			  for(int j = 0 ;j < len ;j ++)
			  {
			    mp[i+1][j+1] = paper[i][j] - '0'; 
			  }
		  memset(vis,0,sizeof(vis)); 
		  sumh = 0;
		  solve(1,n,sumh,len);
		  //print(n ,len); 
		  suml = 0;
		  for(int i = 1;i <= n;i ++)
			  for(int j = 1;j <= len;j ++)
			  {
			    mp1[j][i] = mp[i][j];
			  }
		  
		  memset(vis,0,sizeof(vis)); 
		  memcpy(mp,mp1,sizeof(mp1));
		 // print(len ,n); 
		  
		  
		  solve(1,len,suml,n);

		  //printf("%d %d\n",sumh,suml);
		  return sumh*suml; 
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"1111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"0110",
 "1001",
 "1001",
 "0110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"0",
 "0",
 "0",
 "1",
 "0",
 "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"000",
 "010",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        BoardFoldingDiv2 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
