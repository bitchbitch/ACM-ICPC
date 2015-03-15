// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "PowerOfThreeEasy.cpp"
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
int ans[1000] = {0};

void solve(int t)
{
  
  int k = 0 ; 
  while(t)
  {
    k ++ ; 
    ans[k] += (t % 3);
	t = t/3;
  }
}
class PowerOfThreeEasy
{
        public:
        string ableToGet(int x, int y)
        {
			memset(ans,0,sizeof(ans));
			solve(x);
			solve(y);
			int i ;
			for(i = 200;i >= 0;i --)
				if(ans[i] != 0 )
					break;
	//		printf("%d\n\n",i);
			for(;i >= 1; i --)
				if(ans[i] != 1)
			      return "Impossible";
		  return "Possible";
		}
}; 
