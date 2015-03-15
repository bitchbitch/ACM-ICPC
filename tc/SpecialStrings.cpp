// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "SpecialStrings.cpp"
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

char str[100];
char ans[100];
int len ;
int isok()
{
   for(int i = 0;i < len-1;i  ++)
   {
	  int s = i+1;
      int j = 0;
	  for(;j <= i && s < len ; s++ ,j++ ) 
	  {
		if(ans[j] > ans[s])
			return 0;
		else if(ans[j] < ans[s])
			break;

	  }
	  if(j == i+1 || s == len)
		 {
		    if((i+1)*2 >= len) 
			  return 0 ;
		 }
   }
   return 1 ;
}
void solve(int k)
{
  for(int i = k;i < len ;i ++)
  {
     ans[i] = '1'; 
  }
 // puts(ans);
  for(int i = k+1;i < len; i++)
  {
      ans[i] = '0';
	  if(!isok())
	   ans[i] = '1';
  }
}
class SpecialStrings
{
        public:
        string findNext(string str1)
        {
          len = str1.size();
		  if(len == 1 && str1[0] == '0')
			  return "1";
		  memset(str,0,sizeof(str));
		  for(int i = 0 ;i < len ;i ++)
			  str[i] = str1[i];
		  int i ;
		  for( i = len - 1;i >= 1;i --)
		  {
		       if(str[i] == '0')
			   {
		         strcpy(ans,str);   
			     solve(i);
				 break;
			   }
		  }
		  if(i == 0)
			  return "";
		  string hehe;
		  for(int i = 0 ;i < len ;i ++)
			  hehe.push_back(ans[i]);
		  return hehe;
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01"; string Arg1 = ""; verify_case(0, Arg1, findNext(Arg0)); }
	void test_case_1() { string Arg0 = "00101"; string Arg1 = "00111"; verify_case(1, Arg1, findNext(Arg0)); }
	void test_case_2() { string Arg0 = "0010111"; string Arg1 = "0011011"; verify_case(2, Arg1, findNext(Arg0)); }
	void test_case_3() { string Arg0 = "000010001001011"; string Arg1 = "000010001001101"; verify_case(3, Arg1, findNext(Arg0)); }
	void test_case_4() { string Arg0 = "01101111011110111"; string Arg1 = "01101111011111111"; verify_case(4, Arg1, findNext(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        SpecialStrings ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
