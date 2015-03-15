#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<numeric>
#include<sstream>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>

using namespace std ;

double xa , xb , xc , xd , ya , yb , yc , yd , za , zb , zc , zd ;
double F1ab , F1cd , F2 ,F3ab , F3cd , F32 , F , xm , ym , zm , xn1 , yn1 , zn1 ;
int Case ;  
int main()
{
	
	scanf( "%d" , &Case ) ;
	while( Case-- )
	{
		scanf( "%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf" , &xa , &ya ,&za ,&xb, &yb, &zb ,&xc, &yc ,&zc , &xd , &yd , &zd ) ;
	 	F1ab = ( long double )( ( xb - xa ) * ( xb - xa ) + ( yb - ya ) * ( yb - ya ) + ( zb - za ) * ( zb - za ) );
		F1cd = ( long double )( ( xd - xc ) * ( xd - xc ) + ( yd - yc ) * ( yd - yc ) + ( zd - zc ) * ( zd - zc ) );
		F2 = ( long double )( ( xb - xa ) * ( xd - xc ) + ( yb - ya ) * ( yb - ya ) + ( zb - za ) * ( zb - za ) );
		F3ab = ( long double )( ( xb - xa ) * ( xc - xa ) + ( yb - ya ) * ( yc - ya ) + ( zb - za ) * ( zc - za ) );
		F3cd = ( long double )( ( xd - xc ) * ( xc - xa ) + ( yd - yc ) * ( yc - ya ) + ( zd - zc ) * ( zc - za ) );
		xm = ( long double )( ( xb - xa ) * ( F3ab * F1cd - F3cd * F2 ) / ( F1ab * F1cd - F2 * F2 ) + xa );
		ym = ( long double )( ( yb - ya ) * ( F3ab * F1cd - F3cd * F2 ) / ( F1ab * F1cd - F2 * F2 ) + ya ) ;
		zm = ( long double )( ( zb - za ) * ( F3ab * F1cd - F3cd * F2 ) / ( F1ab * F1cd - F2 * F2 ) + za );
		xn1 = ( long double )( ( xd - xc ) * ( F3cd * F1ab - F3ab * F2 ) / ( F2 * F2 - F1ab * F1cd ) + xc );
		yn1 = ( long double )( ( xd - xc ) * ( F3cd * F1ab - F3ab * F2 ) / ( F2 * F2 - F1ab * F1cd ) + yc );
		zn1 = ( long double )( ( xd - xc ) * ( F3cd * F1ab - F3ab * F2 ) / ( F2 * F2 - F1ab * F1cd ) + zc ) ;
		/*cout << xm << endl ;
		cout << ym << endl ;
		cout << zm << endl ;
		cout << xn1 << endl ;
		cout << yn1 << endl ;
		cout << zn1 << endl ;*/
	//	printf( "%f%f%f%f%f%f" , xm , ym , zm , xn1 , yn1 , zn1 ) ;
		double ans = ( long double ) sqrt( ( xm - xn1 ) * ( xm - xn1 ) + ( ym - yn1) * ( ym - yn1 ) + ( zm - zn1 ) * ( zm - zn1 ) ) ;
		printf( "%.6lf\n" , ( double ) ans ) ;
		printf( "%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf" , ( double )xm , ( double )ym , ( double)zm , ( double )xn1 , ( double )yn1 , ( double )zn1 ) ;
	}
 	return 0 ;
}
