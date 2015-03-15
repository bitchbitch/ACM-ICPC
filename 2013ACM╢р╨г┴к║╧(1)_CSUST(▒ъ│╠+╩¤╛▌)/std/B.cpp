#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
 
using namespace std;
 
const int MAXN = 2111;
 
struct Dog {
	int pos, speed, range;
	Dog(int p = 0, int s = 0, int r = 0) : pos(p), speed(s), range(r) {}
	inline int get() { return scanf("%d%d%d", &pos, &speed, &range); }
} tmp;
vector<Dog> a;
 
int n, des, cur_pos, cur_time, energy;
 
inline int check(Dog &d, int p, int t) {
	if (d.pos - d.speed * (t + 1) - d.range - 1 > p)
		return 0;
	return (d.pos - p + d.range) / d.speed + 1 - t;
}
 
inline bool miss(Dog &d, int p, int t) {
	return d.pos - d.speed * t + d.range < p;
}
 
inline int calc(Dog &d, int p, int t) {
	return d.pos - d.speed * (t + 1) - d.range - 1 - p;
}
 
int main() {
	while (scanf("%d%d", &des, &n) == 2 && (des != -1 || n != -1)) {
		a.clear();
		for (int i = 0; i < n; ++i) {
			tmp.get();
			a.push_back(tmp);
		}
		cur_time = 0, cur_pos = 0, energy = 0;
		while (cur_pos < des) {
			while (true) {
				int unable = 0;
				for (int i = 0; i < int(a.size()); )
					if (miss(a[i], cur_pos, cur_time))
						a.erase(a.begin() + i);
					else
						++i;
				for (int i = 0; i < int(a.size()); ++i)
					unable = max(check(a[i], cur_pos, cur_time), unable);
				if (unable == 0)
					break;
				cur_time += unable;
				energy += unable;
			}
			int skip = energy + 1;
			for (int i = 0; i < int(a.size()); ++i)
				skip = min(skip, calc(a[i], cur_pos, cur_time));
			++cur_time;
			cur_pos += skip;
			energy -= skip - 1;
		}
		printf("%d\n", cur_time);
	}
}
