#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
 
using namespace std;
 
const int MAXN = 111111;
 
struct Node {
	int x, y, val;
	Node(int _x = 0, int _y = 0, int _val = 0) : x(_x), y(_y), val(_val) {}
	int get() { return scanf("%d%d%d", &x, &y, &val); }
} a[MAXN], *it1, *it2;
 
inline bool operator< (const Node &a, const Node &b) { return a.x < b.x || a.x == b.x && a.y < b.y; }
 
int hor[MAXN], col[MAXN], n, m, c, x, y;
 
inline int value(int x, int y) {
	Node tmp(x, y, 0);
	it1 = lower_bound(a, a + n, tmp);
	it2 = upper_bound(a, a + n, tmp);
	if (it1 == it2)
		return 0;
	else
		return it1->val;
}
 
int main(int argc, char* argv[]) {
	while (scanf("%d", &n) == 1 && n != -1) {
		for (int i = 0; i < n; ++i)
			a[i].get();
		sort(a, a + n);
		for (int i = 0; i < MAXN; ++i)
			hor[i] = col[i] = i;
		for (scanf("%d", &m); m--; ) {
			scanf("%d%d%d", &c, &x, &y);
			if (c == 0)
				swap(hor[x], hor[y]);
			else if (c == 1)
				swap(col[x], col[y]);
			else
				printf("%d\n", value(hor[x], col[y]));
		}
	}
}
