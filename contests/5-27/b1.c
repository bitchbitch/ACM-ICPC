#include <stdio.h>
#include <math.h>
double ans ;
double x1,y11,x2,y2,x,y,r,cx,cy;

void fen(double low ,double high)
{
	double dis(double a,double b,double c,double d);
	double dis1(double i , double j );

	double tx , ty;
	double ansmid1 ;
	double ansmid2 ;
	double mid1 = low+(high-low)*1/3;
	tx = x + r*sin(mid1);
	ty = y + r*cos(mid1);
	ansmid1 = dis(tx,ty,cx,cy) + dis1(tx,ty);
	//printf("%lf %lf %lf\n",tx,ty,ansmid1);
	double mid2 = low +(high - low)*2/3;
	tx = x + r*sin(mid2);
	ty = y + r*cos(mid2);
	ansmid2 = dis(tx,ty,cx,cy) + dis1(tx,ty);
	//printf("%lf %lf %lf\n",tx,ty,ansmid2);
	if(fabs(ansmid2 - ansmid1) < 0.00001)
	{
	   ans = ansmid2;
	   return ;
	}
	if(ansmid1 < ansmid2)
		fen(low,mid2);
	else
		fen(mid1,high);

}
void fen2(double low ,double high)
{
	double dis(double a,double b,double c,double d);
	double dis1(double i , double j );

	double tx , ty;
	double ansmid1 ;
	double ansmid2 ;
	double mid1 = low+(high-low)*1/4;
	tx = x + r*sin(mid1);
	ty = y + r*cos(mid1);
	ansmid1 = dis(tx,ty,cx,cy) + dis1(tx,ty);
	//printf("%lf %lf %lf %lf %lf\n",tx,ty,ansmid1,dis(tx,ty,cx,cy),dis1(tx,ty));
	double mid2 = low +(high - low)*3/4;
	tx = x + r*sin(mid2);
	ty = y + r*cos(mid2);
	ansmid2 = dis(tx,ty,cx,cy) + dis1(tx,ty);
	//printf("%lf %lf %lf\n",tx,ty,ansmid2);
	if(fabs(ansmid2 - ansmid1) < 0.00001)
	{
	   
	   if(ansmid2 < ans)
	   	  ans = ansmid2;
	   return ;
	}
	if(ansmid1 < ansmid2)
		fen2(low,mid2);
	else
		fen2(mid1,high);

}
double dis(double a,double b,double c,double d)
{
	return sqrt(pow(a-c,2)+pow(b-d,2));
}
double dis1(double i , double j )
{
 
	if(i >= x1 && i <= x2)
	{
		if(j > y11)
		{
			return fabs(j-y11);
		}
		else if(j < y2)
		{
			return  fabs(y2 - j);
		}
		else return 0 ;
	}
	else if(j >= y2 && j <= y11)
	{
		if(i < x1 )
		{  
			return fabs(x1 - i);
		}
		else if(i >x2 )
		{
			return fabs(i-x2);
		}
		else return 0 ;

	}
	else if(i < x1 && j > y11)
	{
		return dis(i,j ,x1, y11);
	}
	else if(i > x2 && j > y11)
	{
		return dis(i,j,x2,y11);
	}
	else if(i < x1 && j < y2)
	{
		return dis(i , j , x1, y2);
	}
	else return dis(i,j,x2,y2);
}
int main()
{
	while(scanf("%lf %lf",&cx,&cy) != EOF)
	{
		if(cx == 0 && cy == 0)
			break;
		scanf("%lf %lf %lf",&x,&y,&r);
		scanf("%lf %lf %lf %lf",&x1,&y11,&x2,&y2);
		double tempx, tempy;
		if(x1 < x2 && y11 > y2)
		{
			int p ;
		}
		else if(x1 < x2 && y11 < y2)
		{
			tempy = y11;
			y11 = y2;
			y2 = tempy;
		}
		else if(x1 > x2 && y11 > y2)
		{
			tempx = x1 ;
			x1 = x2;
			x2 = tempx;
		}
		else if(x1 > x2 && y11 < y2)
		{
			tempy = y11;
			y11 = y2;
			y2 = tempy;
			tempx = x1 ;
			x1 = x2;
			x2 = tempx;

		}
		//printf("%lf %lf %lf %lf\n",x1,y11,x2,y2);
		fen(0,3.1415926*2);
		//fen2(0,3.1415926*2);
		printf("%.2lf\n",ans);
	}
	return 0 ;
} 
