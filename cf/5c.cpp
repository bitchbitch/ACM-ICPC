// File Name: 5c.cpp
// Author: darkdream
// Created Time: 2015年03月09日 星期一 12时00分57秒

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
char str[1000005];
int hs[1000005];
int dp[1000005];
struct node{
  int si,val;
  node(){}
  node(int _si,int _val)
  {
     si = _si ; 
	 val =_val;
  }
};
stack <node> st;
int main(){
   scanf("%s",&str[1]);
   int len = strlen(&str[1]);
   int tsum = 0 ; 
   hs[0] = 1; 
   for(int i = 1;i <= len;i ++)
   {
	   if(str[i] == '(')
	   {
	      st.push(node(i,2)); 
	   }
	   else if(str[i] == ')')
	   {
	       if(!st.empty())
		   {
			 node tmp = st.top();
			 dp[i] = tmp.val + dp[tmp.si-1];
			 hs[dp[i]] ++ ; 
			 st.pop();
			 if(!st.empty())
			 {
			    node k = st.top();
				st.pop();
				st.push(node(k.si,k.val+tmp.val));
			 }
		   }
	   }
        
   }
   for(int i = 1000000 ;i >= 0 ;i -- )
   {
     if(hs[i])
	 {
	   printf("%d %d\n",i,hs[i]);
	   break;
	 }
   }
return 0;
}
