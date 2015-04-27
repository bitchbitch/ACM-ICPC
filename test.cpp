// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年04月25日 星期六 12时06分21秒
#include<unistd.h>/*#包含<unistd.h>*/
#include<sys/types.h>/*#包含<sys/types.h>*/
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
#define LL long long

using namespace std;

int main(){

	int m , n ; 
	scanf("%d %d",&n,&m);

int ans ; 
        ans = 0 ; 
        for(int i = 31;i >= 0 ;i --){
            if(((n>>i)&1) ==((m>>i)&1)){
                if((n>>i) & 1)
                    ans += (1 << i);
            }else{
                break;
            }
			//printf("%d\n",ans);
        }
		while(0){
			continue;
		}
	return 0;
}
