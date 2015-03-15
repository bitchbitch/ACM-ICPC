// File Name: h.cpp
// Author: darkdream
// Created Time: 2014年10月18日 星期六 11时35分02秒

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
char str[6000005];
char str1[6000005];
int len; 
int sp;
int change(char c)
{
   if(c >= 'a' && c <= 'z')
	   return c- 'a';
   if(c >= 'A' && c <= 'Z')
	   return c - 'A' + 26;
   if(c >= '0' && c <= '9')
	   return c - '0' + 52;
}
struct node{
	int ne[63];
	int sub;
	int iss;
	int isend;
	int be;
	int en;
}N[220000];
int LN,LT;
struct Trie{
    int newnode()
	{
		LN ++;
		memset(N[LN].ne,-1,sizeof(N[LN].ne));
	    N[LN].sub = -1;
		N[LN].isend = 0 ;
		N[LN].iss = 0 ; 
		N[LN].be = 0 ; 
		N[LN].en = 0 ; 
	    return LN;
	}
	int root ; 
	void init()
	{
       root = newnode();
	}
	int newTrie(Trie T[])
	{
       LT ++;
	   T[LT].init();
	   return LT;
	}
    void insert(Trie T[])
	{
	  int be = sp;
	  while(be < len)
	  {
		  if(str[be+1] == '}')
		  {
		    sp = be + 1;
			return;
		  }
		  int i ;
		  
		  be = be + 3;

          if(str[be-1] == '}') 
		  {
		    sp = be-1;
			return;
		  }
		  if(be + 2 >= len)
		  {
			  return;
		  }
		  int now = root;
		  for(i = be ;str[i] !='"';i ++)
		  {
			  int tt = change(str[i]);

			  if(N[now].ne[tt] == -1)
			  {
				  N[now].ne[tt]= newnode();
			  }
			  now = N[now].ne[tt];
		  }
	      N[now].isend = 1;
		  if(str[i+2] == '"')
		  {
			 N[now].be = i + 2;
			 N[now].iss = 1; 
		     int j = i + 3;   
			 while(str[j] != '"')
			 {
			   j++ ; 
			 }
			 N[now].en = j;
		     be = j; 
		  }else{
			sp = i + 1;
			N[now].be = i + 2;
		    N[now].sub = newTrie(T);
		    T[N[now].sub].insert(T);
			be = sp;
			N[now].en = be;
		  }
	  }
      sp = be;
	}
    

	void query(Trie T[])
	{
	//	debug(root);
		int now = root;
		int i ;
		for(i = sp;str1[i] != '"'  ;i ++)
		{
			int tt = change(str1[i]);
			if(N[now].ne[tt] != -1)
			{
				now =N[now].ne[tt];	
			}else {
				//printf("%d\n",i);
				printf("Error!\n");
				return;
			}
		}  
		sp = i + 3; 
		if(N[now].isend == 0)
		{ 
			printf("Error!\n");
			return;
		}
		if(sp >= len)
		{
		    for(int i = N[now].be ;i <= N[now].en;i ++)
				printf("%c",str[i]);
			printf("\n");
		}else{
			if(N[now].sub == -1)
			{
				printf("Error!\n");
			    return;
			}
			T[N[now].sub].query(T);
		}
	}
}T[11005];
int main(){
	int t; 
	scanf("%d",&t);
	int kt =  0 ; 
	while(t--)
	{
	  memset(T,0,sizeof(T));
	  memset(N,0,sizeof(N));
      scanf("%s",str);
	  len = strlen(str);
	  sp = -1;
	  LN = 0;
	  LT = 0;
	  T[0].init();
	  T[0].insert(T);
	  int q; 
	  scanf("%d",&q);
	  for(int i = 1;i <= q;i ++)
	  {
	     scanf("%s",str1);
		 sp = 1; 
		 len = strlen(str1);
		 T[0].query(T);
	  }
	}
return 0;
}
