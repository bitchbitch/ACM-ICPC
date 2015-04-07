// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年04月06日 星期一 20时13分24秒

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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define LL long long
#define M 1000000007
using namespace std;
using namespace __gnu_pbds;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>t;
int main(){
	t.insert(1);
	t.insert(2);
	t.insert(3);
	t.insert(4);
	printf("%d\n",*t.find_by_order(0));
    return 0 ; 
}

