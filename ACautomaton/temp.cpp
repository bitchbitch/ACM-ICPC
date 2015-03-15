// File Name: temp.cpp
// Author: darkdream
// Created Time: 2014年09月11日 星期四 15时18分4秒

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
#define maxn 505000
using namespace std;

int n,m;
int ansr = 0 ;
int ansl = 0 ;
struct Trie
{
    int next[maxn][26],end[maxn],lenth[maxn],numr[maxn];
    vector<int> update[maxn];
    int root,L,K;
    int newnode()
    {
        memset(next[L],0,sizeof(next[L]));
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        K = 0 ;
        root = newnode();
    }
    int insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        int sum = 0 ; 
        for(int i = 0;i < len ;i++)
        {
            int tt ;
            if(buf[i] >= 'a')
            {
               tt = buf[i] - 'a';             
            }else{
               tt = buf[i] - 'A';
            }
            if(tt == 'r' - 'a')
                sum ++ ;
            if(next[now][tt] == 0)
            {
                next[now][tt] = newnode();
            }
            now = next[now][tt];
        }
        if(end[now])
            return end[now];
        K ++ ;
        update[K].clear();
        end[now] = K;
        numr[K] = sum;
        lenth[K] = len;
        return K;
    }
    void up(int x)
    {
      queue<int> Q;
      Q.push(x);
      while(!Q.empty())
      {
         int now = Q.front();
         Q.pop();
         int lu = update[now].size();
         for(int i = 0 ;i < lu ;i ++)
         {
            if(numr[now] < numr[update[now][i]] ||(numr[now] == numr[update[now][i]] && lenth[now] < lenth[update[now][i]]))
            {
                numr[update[now][i]] = numr[now];
                lenth[update[now][i]] = lenth[now];
                Q.push(update[now][i]);
            }
         }
      }
    }
    void query(char buf[])
    {
       int len = strlen(buf);
       int now = root;
       int sum = 0 ;
       int ok = 0 ; 
       for(int i = 0 ;i < len; i++)
       {
            int tt ;
            if(buf[i] >= 'a')
            {
               tt = buf[i] - 'a';             
            }else{
               tt = buf[i] - 'A';
            }
            if(tt == 'r' -'a')
                sum ++ ;
			if(next[now][tt] == 0)
				ok = 1;
            now = next[now][tt];
       }
       if(ok == 1)
       {
          ansr += sum;
          ansl += len;
       }
       else if(end[now])
       {
          ansr += numr[end[now]];
          ansl += lenth[end[now]];
       }else{
          ansr += sum;
          ansl += len;
	   }
    }
};

Trie ac;
char buf[300000];
char temp1[100005];
char temp2[100005];
int main(){
    int n , m ; 
    ac.init();
    scanf("%d",&n);
    getchar();
    gets(buf);
    scanf("%d",&m);
    for(int i = 1;i <= m;i ++)
    {   
      scanf("%s",temp1);
      int num2 = ac.insert(temp1);
      scanf("%s",temp2);
      int num1 = ac.insert(temp2);
      ac.update[num1].push_back(num2);
      ac.up(num1);
    }
	
	char *p = buf;
    while(sscanf(p,"%s",temp1) != EOF)
    {
       p = strstr(p,temp1) + strlen(temp1);
       ac.query(temp1);
    }
    printf("%d %d\n",ansr,ansl);
    
	return 0;
}
