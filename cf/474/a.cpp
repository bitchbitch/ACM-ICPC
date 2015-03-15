// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年10月06日 星期一 23时28分57秒

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
char  str[102];
char  tp[4][100] = {"qwertyuiop",
"asdfghjkl;",
"zxcvbnm,./",
};
int main(){
    scanf("%s",str);
	if(str[0] == 'L')
	{
	   scanf("%s",str);
	   for(int i = 0;i < strlen(str);i ++)
	   {
	        for(int j = 0;j <= 2;j ++)
			{
			   if(strchr(tp[j],str[i]))
			   {
			     printf("%c",tp[j][strchr(tp[j],str[i]) - tp[j] +1]);
			   }
			}
	   }
	}
  else{
	   scanf("%s",str);
	   for(int i = 0;i < strlen(str);i ++)
	   {
	        for(int j = 0;j <= 2;j ++)
			{
			   if(strchr(tp[j],str[i]))
			   {
			     printf("%c",tp[j][strchr(tp[j],str[i]) - tp[j] - 1]);
			   }
			}
	   
	   }
  }
return 0;
}
