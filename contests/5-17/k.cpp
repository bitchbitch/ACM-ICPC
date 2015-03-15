// File Name: k.cpp
// Author: darkdream
// Created Time: 2013年05月18日 星期六 14时31分10秒

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

using namespace std;
int piao[105],cost[105],people[105];
struct node
{
	int num;
	int site;
	bool operator < (const node &x) const 
	{
		return num < x.num;
	}
}nodes[105];
int main()
{

	int t ;
//	freopen("/home/plac/problem/input.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		memset(piao,0,sizeof(piao));
		memset(cost,0,sizeof(cost));
		memset(people,0,sizeof(people));
		int n ,Max = 10000000;
		scanf("%d",&n);
		for(int i= 2;i <=n; i++)
		{
			scanf("%d",&people[i]);
			piao[people[i]]++;
		}
		for(int i = 2; i <=n; i ++)
			scanf("%d",&cost[i]);
		int people1[105];
		for(int may = (piao[1] == 0 || piao[1] == 1) ? 2:piao[1] ; may < n; may ++)
		{
			memset(nodes,0,sizeof(nodes));
			int sum = 0;
			int temp = piao[1];
			for(int i = 2; i <= n; i++)
				if(piao[i] > may -1)
					sum+= piao[i]-(may-1);
			if(sum + piao[1] > may)
				continue;
            for(int i = 0 ; i <= n;i ++)
				people1[i] = people[i];
			int j = 0 , Sum = 0 ;
			for(int i = 2; i <=n; i++)
			{
				if(piao[i] > may-1)
				{ j = 0;
					for( int k = 2; k <= n; k ++)
						if(people1[k] == i)
						{
							nodes[j].num = cost[k];
							nodes[j].site = k ;
							j++;
						}
				   sort(nodes,nodes+j);
			        for(int k = 0; k < piao[i]-(may-1); k++  )
		 	        {
				    Sum += nodes[k].num;
				    people1[nodes[k].site] = 1;
				     piao[1]++;
			       }
 
				}

			}
 


			memset(nodes,0,sizeof(nodes));
			j = 0;
			for(int  i = 2 ;i <= n;i ++)
			{
			   if(people1[i] != 1)
			   {
			       nodes[j].num = cost[i];
				   nodes[j].site  = i ;
			       j++;
			   }

			}

			sort(nodes,nodes+j);
			for(int k = 0; k < j ; k++  )
			{
				if(piao[1] >= may)
					break;
				Sum += nodes[k].num;
				people1[nodes[k].site] = 1;
				piao[1]++;
			}

			if(Sum < Max)
			{	
				Max = Sum;
			
			}
			piao[1] = temp;
		}
    printf("%d\n",Max);

	}
	return  0 ;

}
