#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int MOD = (int)1e9 + 7;
const int MAXN = 1111;

int n, ways[MAXN], new_ways[MAXN];

int main() {
	while (scanf("%d", &n) == 1 && (n != -1)) {
		if (n % 3 != 0) {
			puts("0");
			continue;
		}
		for (int i = 0; i <= n; ++i)
			ways[i] = 0;
		ways[0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= n; ++j)
				new_ways[j] = 0;

			for (int j = 0; j <= n; ++j) {
				if (j >= 1)
					new_ways[j - 1] = (new_ways[j - 1] + ways[j]) % MOD;
				if (j + 2 <= n) {
					new_ways[j + 2] = (new_ways[j + 2] + ways[j]) % MOD;
					if (j == 0)
						new_ways[j + 2] = (new_ways[j + 2] + ways[j]) % MOD;
				}
			}
			for (int j = 0; j <= n; ++j)
				ways[j] = new_ways[j];
		}
		printf("%d\n", ways[0]);
	}
}
