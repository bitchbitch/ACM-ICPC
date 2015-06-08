/************************************************************
 * Author : cijianzy
 * Email : cijianzy@gmail.com 
 * Last modified : 2015-05-19 18:15
 * Filename : solvedata.cpp
 * Description :
 * *********************************************************/
// File Name: solvedata.cpp
// Author: cijianzy
// Created Time: 2015年05月19日 星期二 16时34分27秒

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
#include<unistd.h>
#define LL long long

using namespace std;
string  str[100];
int main(){
    for(int i = 1;i <= 67 ;i ++)
        cin >> str[i];
   sort(str+1,str+1 + 67);
   puts("************");
   int sum = 1; 
   cout << str[1] <<";" ; 
   for(int i = 2;i <= 67 ;i ++)
        if(str[i] != str[i-1])
            cout << str[i] << ";" ; 
   cout << sum << endl ; 
   return 0 ; 
}
