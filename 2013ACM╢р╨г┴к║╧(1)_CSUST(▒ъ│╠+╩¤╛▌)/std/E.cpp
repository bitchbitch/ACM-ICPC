#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0): x(x), y(y) {}
};

int det(const Point &a, const Point &b) {
	return a.x * b.y - b.x * a.y;
}

double sqr(double x) {
	return x * x;
}

double dist(const Point &a, const Point &b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

Point operator -(const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y);
}

bool cross(const Point &a, const Point &b, const Point &c, const Point &d) {
	if ((det(c - a, b - a) > 0) ^ (det(b - a, d - a) > 0))
		return false;
	if ((det(a - c, d - c) > 0) ^ (det(d - c, b - c) > 0))
		return false;
	return true;
}

Point A, B, C, D;

int main() {
	for (;;) {
		scanf("%d%d%d%d", &A.x, &A.y, &B.x, &B.y);
		if (A.x == 0 && A.y == 0 && B.x == 0 && B.y == 0)
			break;
		scanf("%d%d%d%d", &C.x, &C.y, &D.x, &D.y);
		double ans;
		if (cross(A, B, C, D))
			ans = min((dist(A, C) + dist(B, C)) / 2.0, (dist(A, D) + dist(B, D)) / 2.0);
		else
			ans = dist(A, B) / 2.0;
		static int Test = 1;
		printf("Case %d: %.3f\n", Test++, ans);
	}
}
