// File Name: temp.cpp
// Author: darkdream
// Created Time: 2014年09月11日 星期四 15时18分128秒

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
#include<queue>
#define LL long long
#define maxn 50000
using namespace std;
struct Trie
{
   int next[maxn][128],fail[maxn],end[maxn];
   int root, L;
   int newnode()
   {
       for(int i = 0 ;i < 128;i ++)
          next[L][i] = -1;
       end[L++] = 0 ;
       return L-1;
   }
   void  init()
   {
      int L = 0 ; 
      root = newnode();
   }
   void  insert(char buf[],int k)
   {
      int len = strlen(buf);
      int now = root;
      for(int i = 0 ;i < len ;i ++)
      {
         if(next[now][buf[i]] ==  -1)
         {
             next[now][buf[i]] = newnode();
         }
         now = next[now][buf[i]];
      }
      end[now] = k;
   }
   void build()
   {
       queue<int> Q; 
       //这里为何要用优先队列来解决这个问题，主要原因是fail指针是按层数来的。
       fail[root] = root; 
       for(int i = 0;i < 128;i ++)
       {
            if(next[root][i] == -1)
            {
               next[root][i] = root;  //指向root 是没有问题的，我们主要是通过end 数组对个数进行计数的。    
            }else{
               fail[next[root][i]] = root;
               Q.push(next[root][i]);
            }
       }
       while(!Q.empty())
       {
          int now = Q.front();
          Q.pop();
          for(int i = 0 ;i < 128;i ++)
          {
             if(next[now][i] == -1)
                 next[now][i] =  next[fail[now]][i]; 
             else{
                fail[next[now][i]] = next[fail[now]][i];
                Q.push(next[now][i]);
             }
          }
       }
   }
   int query(char buf[])
   {
      int len = strlen(buf);
      int now = root ; 
      for(int i = 0 ;i < len;i ++)
      {
        now = next[now][buf[i]];
        int temp = now ; 
        while(temp != root)
        {
		   if(end[temp] == 1 )
		   {
		      puts("MAI MAI MAI!"); 
		   }else if(end[temp] == 2)
		   {
		      puts("SONY DAFA IS GOOD!");
		   }
           temp = fail[temp];//  不断的寻找 fail 指针 因为会出线这样的字符串  abcd bcd cd
        }
      }
   }
};
char buf[1000010];
char temp[][10] = {"Apple","iPod","iPhone","iPad","Sony"};
Trie ac;
int main(){
    ac.init();
    for(int i =0 ;i <= 3;i ++  )
	{
	   ac.insert(temp[i],1);
	}
	ac.insert(temp[4],2);
	ac.build();
	while(scanf("%s",buf) != EOF)
	{
        ac.query(buf);	
	}
	return 0;
}
