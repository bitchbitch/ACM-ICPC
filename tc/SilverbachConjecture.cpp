// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "SilverbachConjecture.cpp"
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


int is(int x)
{
  if(x < 4 )
	  return 0 ; 
  for(int i = 2;i < sqrt(x); i ++)
	  if(x % i  == 0 )
		  return 1 ; 
  return 0 ; 
}
class SilverbachConjecture
{
        public:
        vector <int> solve(int n)
        {
		   vector <int> ans;
		   for(int i = 4;i <= n;i ++)
		   {
              int tempa = i ; 
			  int tempb = n - i ; 
			  if(is(tempa) && is(tempb))
				 {
				   ans.push_back(tempa);
				   ans.push_back(tempb);
				   break;
				 }
		   }
		   return ans; 
        }
        

};

