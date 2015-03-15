// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "WinterAndReindeers.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
char stra[100][100];
char strb[100][100];
char strc[100][100];
int LCSLength(char* str1, char* str2, int **b)
{
	int i,j,length1,length2,len;
	length1 = strlen(str1);
	length2 = strlen(str2);

	//双指针的方法申请动态二维数组
	int **c = new int*[length1+1];      //共有length1+1行
	for(i = 0; i < length1+1; i++)
		c[i] = new int[length2+1];      //共有length2+1列

	for(i = 0; i < length1+1; i++)
		c[i][0]=0;        //第0列都初始化为0
	for(j = 0; j < length2+1; j++)
		c[0][j]=0;        //第0行都初始化为0

	for(i = 1; i < length1+1; i++)
	{
		for(j = 1; j < length2+1; j++)
		{
			if(str1[i-1]==str2[j-1])   //由于c[][]的0行0列没有使用，c[][]的第i行元素对应str1的第i-1个元素
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=0;          //输出公共子串时的搜索方向
			}
			else if(c[i-1][j]>c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=1;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=-1;
			}
		}
	}
	len=c[length1][length2];
	for(i = 0; i < length1+1; i++)    //释放动态申请的二维数组
		delete[] c[i];
	delete[] c;
	return len;
}
char str111[100];
int t = -1;

void PrintLCS(int **b, char *str1, int i, int j)
{
	if(i==0 || j==0)
		return ;
	if(b[i][j]==0)
	{
		PrintLCS(b, str1, i-1, j-1);   //从后面开始递归，所以要先递归到子串的前面，然后从前往后开始输出子串
		//printf("%c",str1[i-1]);//c[][]的第i行元素对应str1的第i-1个元素
	    str111[++t] = str1[i-1];
	}
	else if(b[i][j]==1)
		PrintLCS(b, str1, i-1, j);
	else
		PrintLCS(b, str1, i, j-1);
}

class WinterAndReindeers
{
        public:
        int getNumber(vector <string> allA, vector <string> allB, vector <string> allC)
        {
		   memset(strc,0,sizeof(strc));
		   memset(strb,0,sizeof(strb));
		   memset(stra,0,sizeof(stra));
		   
		   for(int i =0 ;i < allA.size();i ++)
		   {
		      int len = allA[i].size();
			  for(int j = 0 ;j < len; j ++)
				  stra[i][j] = allA[i][j];
		   }
		   for(int i =0 ;i < allB.size();i ++)
		   {
		      int len = allB[i].size();
			  for(int j = 0 ;j < len; j ++)
				  strb[i][j] = allB[i][j];
		   }
		   for(int i =0 ;i < allC.size();i ++)
		   {
		      int len = allC[i].size();
			  for(int j = 0 ;j < len; j ++)
				  strc[i][j] = allC[i][j];
		   }
		   int max = 0; 
		  for(int i = 0;i < allA.size();i++)
			   for(int j = 0 ;j <allB.size();j ++ )
		       {
			       int len1 = strlen(stra[i]);
				   int len2 = strlen(strb[j]);
				   memset(str111,0,sizeof(str111));
				   t = -1;
				   int **b = new int *[len1+1];
				   for(int s = 0 ; s < len1 + 1 ; s ++)
					   b[s] = new int[len2 + 1];
				   int len =LCSLength(stra[i],strb[j],b);
				   PrintLCS(b,stra[i],len1,len2);
				   for(int s = 0 ; s < allC.size(); s ++)
			        if(strstr(str111,strc[s]) && len > max)
						max = len;
			   
			   }
		  return max;
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X", "Y"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"X"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"ABCXD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BCDEF"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"CD"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"WE", "LOVE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"WORKING", "FOR", "SANTA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"JK"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"ABCDE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"CDEAB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"B"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AXBADXBBAB", "CDD"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 23; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        WinterAndReindeers ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
