// File Name: 2406.cpp
// Author: darkdream
// Created Time: 2014年09月09日 星期二 20时15分59秒

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
int next[1000005];
char str[1000005];
int len ; 
void knext()
{
   memset(next,0,sizeof(next));
   int j = 0 ; 
   int k = -1;
   next[0] = -1;
   while(j < len -1 )
   {
       if(k == -1 || str[j] == str[k]){
	     j ++ ; 
		 k ++ ;
		 next[j] = k ; 
	   }else{
	     k = next[k];
	   }
   }
   for(int i = 0 ;i <= len ;i ++)
	   printf("%d ",next[i]);
   printf("\n");
   int t = next[len];
   if((len % (len -t) == 0 ) && (t % (len -t) == 0 ))
	   printf("%d\n",len/(len-t));
   else printf("1\n");
}
int main(){
   while(scanf("%s",str) != EOF)
   {
	  len = strlen(str);
      if(len ==  1 && str[0] == '.')
		  break;
      knext();  
   }
return 0;
}
