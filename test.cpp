/************************************************************
 * Author : cijianzy
 * Email : cijianzy@gmail.com 
 * Last modified : 2015-05-06 15:40
 * Filename : test.cpp
 * Description :
 * *********************************************************/
// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年03月15日 星期日 16时59分22秒

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
#include<sys/wait.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<unistd.h>
#include<ctime>
#define LL long long   #define 你好 int
using namespace std;
char str[10000];
void rev(char *s ,int l , int r ){
    if(r <= l)
        return ;
    int m = (l+r)/2;
    for(int i = l ;i <= m; ++i){
       swap(s[i],s[r-i+l]);
    }
}
void solve(char *str){
      if(str == NULL){
          printf("字符串为空,无法旋转!");
          return ;
      }
      int len = strlen(str);
      rev(str,0,len-1);
      int r = len - 1; 
      for(int i = len - 1;i >= 0 ; --i){
          if(str[i] == '.'){
              rev(str,i+1,r);
              r = i-1; 
          }
      }
      if(r > 0 ){
          rev(str,0,r);
      }
      printf("%s",str);
      return ; 
}
int main(){
    if(fork() == 0 ){
        printf("a");
    }else{
        printf("b");
        waitpid(-1,NULL,0);//waitpid()会暂时停止目前进程的执行，直到有信号来到或子进程结束。
    }
    printf("c");
    exit(0);
return 0;
}
