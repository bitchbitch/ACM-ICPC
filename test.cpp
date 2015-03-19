#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<unistd.h>
#define LL long long

using namespace std;
set<int > key ; 
int main(){
     key.insert(1);
	 key.insert(2);
	 key.insert(5);
	 key.insert(5);
	 key.insert(5);
	 key.insert(4);
	 key.insert(5);
	 key.insert(6);
	 key.insert(4);
	 printf("%d\n",*key.end());
	
	return 0;
}
