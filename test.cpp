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
bool isPalindrome(string s) {
        string ans;
        ans.clear();
        for(int i =0 ;i < s.size() ;i ++){
            if(s[i] >= 'A' && s[i] <= 'Z')
                ans.push_back(s[i]-'A' +'a');
            if(s[i] >= 'a' && s[i] <= 'z');
                ans.push_back(s[i]);
        }
        
        if(ans.size() == 1)
            return 1;
        int k = ans.size()/2 ;
        for(int i = 0 ;i <= k ;i ++)
            if(ans[i] != ans[ans.size()-1-i])
                return 0 ;
		cout << ans<<endl ; 
        return 1;
    }
int main(){
	string tmp ; 
	cin >> tmp ; 
	isPalindrome(tmp);
	return 0;
}
