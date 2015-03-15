// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "RectangleCoveringEasy.cpp"
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


class RectangleCoveringEasy
{
        public:
        int solve(int a, int b, int c, int d)
        {
		    if(a > b)
				swap(a,b);
			if(c > d)
				swap(a,b);
			if(c <= a && d <= b )
				return -1;
			if(c > a && d > b)
			   return 1;
			if(c > a && d == b)
				return 1;
			if(c == a && d > b )
				return 1;
			return -1;

		}
        

};

