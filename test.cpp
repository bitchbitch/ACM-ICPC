// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年04月25日 星期六 12时06分21秒
#include<unistd.h>/*#包含<unistd.h>*/
#include<sys/types.h>/*#包含<sys/types.h>*/
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
int xadd[] = {0,0,1,-1};
    int yadd[] = {1,-1,0,0};
    
    vector<vector<bool> >  vis;
    int n , m; 
    int ok(int x, int y){
        if(x < n && x >= 0 && y < m && y >= 0){
            return 1;     
        }   
        return 0 ; 
    }
    void dfs(int x,int y,vector<vector<char> > &tmp){
        int tx,ty;
        for(int i = 0 ;i <= 3; i ++){
            tx = x + xadd[i];
            ty = y + yadd[i];
            if(ok(tx,ty) && tmp[tx][ty] == '1' && vis[tx][ty] == 0 ){
                vis[tx][ty] = 1; 
                dfs(tx,ty,tmp);
            }
        }
    }
    int numIslands(vector<vector<char> > &grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i = 0 ;i < n; i ++){
            vis.push_back(vector<int> tmp(m,0));
        }
        int sum = 0 ; 
        for(int i = 0 ;i < n ;i ++)
            for(int j = 0 ;j < m ;j ++){
                if(grid[i][j]){
                    if(!vis[i][j]){
                        sum ++ ; 
                        vis[i][j] = 1 ;
                        dfs(i,j,grid);
                    }
                }
            }
        return sum; 
    }
int main(){
	return 0;
}
