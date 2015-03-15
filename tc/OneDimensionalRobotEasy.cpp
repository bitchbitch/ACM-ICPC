// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "OneDimensionalRobotEasy.cpp"
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


class OneDimensionalRobotEasy
{
        public:
        int finalPosition(string commands, int A, int B)
        {
          int len = commands.size();
		  int b = 0 ; 
		  for(int i = 0 ;i < len ;i ++)
		  {
		     if(commands[i] == 'L' &&  b != -A)
				 b--;
			 else if(commands[i] == 'R' && b != B)
				 b ++;
		  }
		  return b;
		}
        

};

