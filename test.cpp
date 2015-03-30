// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年03月26日 星期四 22时37分15秒

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
#include<queue>
#define LL long long

#define maxn 105

using namespace std;
struct node{
  int l , r ; 
  node(){}
  node(int _l ,int _r)
  {
    l = _l ; 
	r = _r ; 
  }
  bool operator <(node a) const
  {
     return l > a.l ;
  }
};
priority_queue <node> qu;
int n ; 
int main(){ 
	int tt =0 ; 
	for(int i= 1;i <= 40; i++)
		for(int j = 1;j <= 40 ;j ++)
			for(int ij = 1;ij <= 40 ;ij ++)
				for(int ji = 1;ji <= 40;ji ++ )
					tt ++ ;
	printf("%d\n",tt);
return 0;
}
