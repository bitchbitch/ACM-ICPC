// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "FizzBuzzTurbo.cpp"
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

typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;


class FizzBuzzTurbo
{
        public:
        vector<long long> counts(long long A, long long B)
        {
          long long a1, b1,a2,b2,a3,b3 ;
		  vector<long long> VI; 
		  A = A - 1; 
		  a3 = A/3;
		  b3 = B/3;
		  a3 = b3 - a3;
		  a1 = A/5;
		  b1 = B/5;
		  a1 = b1 - a1;
          a2 = A/15;
		  b2 = B/15;
		  a2 = b2 - a2;
		  VI.push_back(a3-a2);
		  VI.push_back(a1-a2);
		  VI.push_back(a2);
		  return VI;
		  
		}
        

};

