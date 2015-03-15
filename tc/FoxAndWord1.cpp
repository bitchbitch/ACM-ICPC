// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "FoxAndWord.cpp"
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


int kmp(string a, string b)
{
   int pi[100];
   int m = b.size();
   memset(pi,0,sizeof(pi));
   pi[0] = -1; 
   int k = -1 ; 
   for(int i = 1 ;i < m ; i ++)
   {
      while(k >= 0 && b[k+1] != b[i]) 
	       k = pi[k];
	  if(b[k+1] == b[i])
		  k = k +1;
	  pi[i] = k; 
   }
   int n = a.size();
   int q = -1 ; 
   for(int i = 0;i < n;i ++)
   {
       while(q >= 0 && b[q+1] != a[i])
	      q = pi[q];
	   if(b[q+1] == a[i])
		  q = q +1;
	   if(q == m -1)
		{
		  return 1;
		}
   }
   //printf("***");
   return 0 ; 
   
}

class FoxAndWord
{
        public:
        int howManyPairs(string words[])
        {
         //   return words.size();
          int sum = 0 ; 
			for(int i = 0;i < 32 ;i ++)
				for(int j = i + 1;j < 32; j ++)
				{
				  string temp = words[i] + words[i];
                  if(kmp(temp,words[j]))
				   {		  sum ++ ;
				       cout << words[i] << "  " << words[j] << endl; 
				   }
				}
			
			printf("%d\n",sum);  

		}
};
