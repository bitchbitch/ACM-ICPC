// File Name: queue.cpp
// Author: darkdream
// Created Time: 2014年04月03日 星期四 15时27分16秒

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
#include<limits>
#include<queue>
using namespace std;
struct node{
	node(){};
	node(int i){
		x = i ; 
	}
	node(int i , int j ){
	   x = i ; 
	   y = j ; 
	}
    friend bool operator < (node n1,node n2){
	  return n1.x > n2.x;
	}
	int x, y ;
};
int main(){
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   priority_queue<node> q;  
   for(int i = 1;i <= 5;i ++)
   {
      q.push(node(i,5-i + 1));
   }
   for(int i = 1;i <= 5;i ++)
   {
      cout << q.top().x <<"  " <<q.top().y << endl;
	  q.pop();
   }
return 0;
}
