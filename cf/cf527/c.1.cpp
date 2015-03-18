// File Name: c.1.cpp
// Author: darkdream
// Created Time: 2015年03月18日 星期三 10时08分02秒

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
int w,h , n; 
set<int>  wss,hs;
multiset<int> mwss,mhs;
char str[10];
int main(){
	scanf("%d %d %d",&w,&h,&n);
	wss.insert(0);
	wss.insert(w);
	hs.insert(h);
	hs.insert(0);
	mhs.insert(h);
	mwss.insert(w);
	set<int>::iterator l , r, m ; 
	multiset<int>::iterator  tmp ; 
	for(int i = 1;i <= n;i ++)
    {
	   int tmpv; 
	   scanf("%s %d",str,&tmpv);
	   if(str[0]== 'H'){
		 if(hs.find(tmpv) == hs.end())
		 {
		     hs.insert(tmpv);
			 l = hs.find(tmpv);
			 l -- ; 
			 r = hs.find(tmpv);
			 r ++;
		     int t = *r - *l;
		//	 printf("%d\n",t);
             tmp = mhs.find(t);
             int k = * tmp ; 
			 mhs.erase(tmp);
			 mhs.insert(*r-tmpv);
			 mhs.insert(tmpv-*l);
			 
		 }
	   }else{
		 if(wss.find(tmpv) == wss.end())
		 {
		     wss.insert(tmpv);
			 l = wss.find(tmpv);
			 l -- ; 
			 r = wss.find(tmpv);
			 r ++;
		     int t = *r - *l;
		//	 printf("%d\n",t);
             tmp = mwss.find(t);
             int k = * tmp ; 
			 mwss.erase(tmp);
			 mwss.insert(*r-tmpv);
			 mwss.insert(tmpv-*l);
		 }
	   
	   }
	   tmp = mhs.end();
	   tmp -- ; 
	   LL sum = *tmp;
	   //printf("%d ",*tmp);
	   tmp = mwss.end();
	   tmp -- ;
	   sum *= (*tmp);
	   //printf(" %d\n",*tmp);
	   printf("%I64d\n",sum);
	}
return 0;
}
