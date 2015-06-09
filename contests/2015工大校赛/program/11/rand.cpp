// File Name: rand.cpp
// Author: cijianzy
// Created Time: 2015年06月07日 星期日 15时27分13秒

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
#define maxn 100005
#define keytree ch[ch[root][1]][0]
using namespace std;
int randlr(int l , int r){
    if(r <=  l )
        swap(l,r);
    if(r == l)
        return l; 
    return rand()%(r-l+1) + l ;  
}

struct SplayTree{
    int ch[maxn][2];
    int root , top1;
    int ok = 0 ; 
    inline void NewNode(int &x, int key ){
        x = ++top1;
        ch[x][0] = ch[x][1]  = 0 ; 
        keys[x] = key ;
    }
    void init(int n){
        ch[0][0] = ch[0][1] = 0 ;
        root = top1 = 0; 
        NewNode(root,rand());
        for(int i = 1;i < n;i ++)
            insert();
        ok= 0 ; 
        printp(1);
        puts("");
        ok = 0 ; 
        printm(1);
        puts("");
    }
    void printm(int k){
        if(k == 0 )
            return ; 
        printm(ch[k][0]);
        if(ok == 0){
            printf("%d",k);
            ok = 1 ; 
        }else printf(" %d",k);
        printm(ch[k][1]);
    }
    void printp(int k){
        if(k == 0 )
            return ; 
        if(ok == 0){
            printf("%d",k);
            ok = 1 ; 
        }else printf(" %d",k);
        printm(ch[k][0]);
        printm(ch[k][1]);
    }
    void insert(){
         int key = rand();
         int x = root ;
         for(;;){
             int f = (key > keys[x]);
             if(ch[x][f] == 0 ){
                 NewNode(ch[x][f],key);
                 return ; 
             }else{
                x = ch[x][f];
             }
         }
    }
    
    int keys[maxn];
}spt;
int n ;
int main(){ 
         
      freopen("in.txt","w",stdout);
      srand(time(NULL));
      printf("1000\n");
      for(int i = 1;i <= 1000 ;i ++){
        n = randlr(1,1000);
        printf("%d\n",n);
        spt.init(n);
      }
return 0;
}
