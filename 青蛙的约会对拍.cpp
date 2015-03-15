/*
 * hdu2669.c
 *
 *  Created on: 2011-9-13
 *      Author: bjfuwangzhu
 */

#include<stdio.h>
int x, y;
int extend_gcd(int a, int b) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = extend_gcd(b, a % b);
    int tx = x;
    x = y, y = tx - a / b * y;
    return d;
}
int main() {
    int a, b, d;
	    freopen("/home/plac/problem/input.txt","r",stdin);
	    freopen("/home/plac/problem/output1.txt","w",stdout);

    while (scanf("%d %d", &a, &b) != EOF) {
        d = extend_gcd(a, b);
        if (d != 1 || d != -1) {
            puts("sorry");
            continue;
        }
        while (x < 0) {
            x += b, y -= a;
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}
