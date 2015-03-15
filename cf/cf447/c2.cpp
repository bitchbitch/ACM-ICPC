// File Name: c2.cpp
// Author: darkdream
// Created Time: 2014年07月14日 星期一 15时29分45秒

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
#include<climits>
#include<queue>

using namespace std;
int n;
int m;
int res[100002][2];
int x[100002];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    int ans = min (2, n), cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int t = 0; t < 2; t++) {
            res[i][t] = 1;
            if (i + 1 < n && x[i] < x[i + 1]) res[i][t] += res[i + 1][t]; 
        }   
        if (i + 2 < n && x[i] + 2 <= x[i + 2]) res[i][1] = max (res[i][1], res[i + 2][0] + 2);
        ans = max (ans, max (res[i][0], res[i][1]));
        cur = max (cur, res[i][0]);
    }
    if (cur < n) cur++;
    ans = max (ans, cur);
    printf ("%d\n", ans);
    return 0;
}
