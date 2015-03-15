// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "FixedDiceGameDiv2.cpp"
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


class FixedDiceGameDiv2
{
        public:
        double getExpectation(int a, int b)
        {
			int sum = 0 ; 
			int num = 0 ; 
			for(int i = 1;i <= b;i ++)
			{
			   for(int j = 1; j <= a ;j ++)
			   {
			       if(j > i )
				   {
				    num ++ ; 
					sum += j ;
				   }
			   }
			}
			return sum*1.0/num;
		}
        

};

