// File Name: hashnum.cpp
// Author: darkdream
// Created Time: 2013年11月24日 星期日 22时55分51秒

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
#define NHASH 8999           /* 保证它是素数 */
 
hashnum(p)
char *p;
{
    unsigned int sum = 0;
    for ( ; *p; p++)
	sum = (sum << 3) + *p;
    return sum % NHASH;
}
#include 
 
main() {
    FILE *in;
    char line[100], *p; 
    in = fopen ("/usr/share/dict/words", "r");
    while (fgets (line, 100, in)) {
	for (p = line; *p; p++)
	    if (*p == '\n') { *p = '\0'; break; }
	printf("%6d %s\n", hashnum(line), line);
    }
    exit (0);
}
