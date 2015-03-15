#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int64;
const int N = 2000010;

int n, add, m;
int a[N];
int que[N], head, tail;
int64 sum[N];

int main() {
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			a[i + n] = a[i];
			sum[i] = sum[i - 1]  + a[i];
		}
		m = n * 2;
		for (int i = n + 1; i <= m; ++i)
			sum[i] = sum[i - 1] + a[i];
		
		int ans = 0;
		head = 1, tail = 0;
		for (int i = m; i > n; --i) {
			while (head <= tail && sum[que[tail]] >= sum[i])
				tail--;
			que[++tail] = i;
		}
		for (int i = n; i; --i) {
			while (head <= tail && que[head] - i > n)
				++head;
			if (sum[que[head]] - sum[i] >= 0)
				++ans;
			while (head <= tail && sum[que[tail]] >= sum[i])
				tail--;
			que[++tail] = i;
		}
		printf("%d\n", ans);
	}
}
