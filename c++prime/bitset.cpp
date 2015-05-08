// File Name: hash_map.cpp
// Author: darkdream
// Created Time: 2015年05月01日 星期五 19时46分13秒

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
//#include<ext/hash_map>
#define LL long long

using namespace std;
//using namespace __gnu_cxx;
map<string,string> mp;
bitset<10000> val(0);
int main(){
	mp["你好"] = "haha";
	int n;
	while(scanf("%d",&n) !=  EOF){
		if(val[n])
			printf("Ture\n");
		else printf("False\n");
		val[n] = 1; 
	}
return 0;
}
