// File Name: socket.cpp
// Author: darkdream
// Created Time: 2015年05月02日 星期六 10时15分41秒

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
#include<sys/socket.h>
#include<sys/types.h>

#define LL long long

using namespace std;

typedef struct sockaddr SA;
//int socket(int domain,int type,int protocol);
int tmp = socket(1,1,0);
int main(){

	printf("%d %d\n",AF_INET,SOCK_STREAM);
return 0;
}
