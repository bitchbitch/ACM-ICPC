// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "CountryGroupHard.cpp"
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

int color[1000];
int tmp[1000];
int n ;
int ok = 0 ; 
void isok()
{
   int tok = 0 ; 
   for(int i = 0 ;i < n;i ++)
   {
      if(color[i] != 0 ) 
		  tok = 1; 
   }
   if(tok == 0 && n != 1)
	   return;
   /*for(int i = 0;i < n;i ++)
	   printf("%d ",color[i]);
   printf("\n");*/
   ok ++ ; 
}
void dosolve(int k,int be, int c)
{
	if(ok == 2)
		return;
	 if(k == n)
	 {
	    isok();
		return;
	 }
	 if(tmp[k] == 0)
	 {
		 dosolve(k+1,be,c);
	     return;
	 }
     if(be > k)
	 {
       if(tmp[k] == c)
	     dosolve(k+1,be,c);
	   else return;
	 }else{
	   for(int j = max(be,k-tmp[k]+1); j <= k;j ++)
	   {
		  if(j + tmp[k] > n)
			  break;
		  for(int s = j ; s < j + tmp[k]; s ++)
			  color[s] = 1; 
	      dosolve(k+1,j + tmp[k],tmp[k]);
		  for(int s = j ; s < j + tmp[k]; s ++)
			  color[s] = 0; 
	   }
	 }
}
class CountryGroupHard
{
        public:
        string solve(vector <int> a)
        {
			ok = 0 ;
		    n = a.size();
			for(int i= 0 ;i< n;i ++)
				tmp[i] = a[i];
			dosolve(0,0,-1);
			/*int n = a.size();
		
			memset(color,0,sizeof(color));
            int be = 0 ; 
			for(int i = 0 ;i < n ;i ++)
			{
			    if(a[i] != 0 ) 
				{
					int k = be; 
					k = max(k, i-a[i] + 1);
                    for(int j = k ;j < k +a[i] ;j ++)
						color[j] = a[i]; 
					be = k + a[i]; 
				}
			}
            for(int i= 0 ;i < n;i ++)
			{
			  printf("%d ",color[i]);
			}
			puts("");*/
		    //printf("%d\n",ok);			
			if(ok == 1 )
			return "Sufficient";
			return "Insufficient";
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,2,3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {0,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Insufficient"; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {0,3,0,0,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {0,0,3,3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Insufficient"; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {2,2,0,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CountryGroupHard ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
