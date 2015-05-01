/************************************************************
 * Author : darkdream
 * Email : cijianzy@gmail.com 
 * Last modified : 2015-04-30 22:05
 * Filename : book.cpp
 * Description :
 * *********************************************************/
// File Name: book.cpp
// Author: darkdream
// Created Time: 2015年04月30日 星期四 20时19分34秒

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
class Quote{
	public:
		Quote() ;
		Quote(const std::string &book,double sales_prices):
			bookNo(book),price(sales_prices){}
		string isbn() const {return bookNo;}
		virtual double net_price(size_t n) const{
			return n * price;
		}
		virtual ~Quote();
	private:
		string bookNo;
	protected:
		double price = 0.0;
};
class Bulk_quote:public Quote{
	public:
		Bulk_quote(){}
		Bulk_quote(const string &,double ,size_t,double );
		double net_price(size_t) const override;
	private:
		size_t	min_qty = 0 ; 
		double  discount = 0.0;
};
int main(){

	return 0;
}
