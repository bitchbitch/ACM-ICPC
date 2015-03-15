// File Name: 1159.cpp
// Author: darkdream
// Created Time: 2014年07月12日 星期六 16时08分49秒

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
#include<climits>
#include<queue>

using namespace std;
char str[1000];
char str1[1000];
int c[1000][1000];
int main(){
    while(scanf("%s %s",str,str1) != EOF)
	{
	  memset(c,0,sizeof(c)); 
	  int len = strlen(str);
	   int len1 = strlen(str1);
	   for(int i = 1;i <= len;i ++)
	    for(int j = 1;j <= len1;j ++)
		{
	        if(str[i-1] == str1[j-1])
			{
			   c[i][j] = c[i-1][j-1] + 1;
			}else c[i][j] = max(c[i][j-1],c[i-1][j]);
	    }
	   printf("%d\n",c[len][len1]);
	}
return 0;
}
