#include <iostream>
#include <iomanip>
#include <cmath>
#define pi acos(-1.0)
using namespace std;

inline int sgn(double x)
{
	return fabs(x) < 1e-6 ? 0 : (x < 0 ? -1 : 1); 
}

struct point{
	double x,y;
	bool operator <(const point &a)
	{
		if(sgn(x - a.x) == 0)
			return y < a.y;
		return x < a.x;
	}
}p[25];

double len(point a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

double dot(point a,point b)
{
	return a.x * b.x + a.y * b.y;
}
double cross(point a,point b)
{
	return (a.x*b.y) - (a.y * b.x);
}

int main ()
{
	int n;
	while(cin >> n)
	{
		if(n < 3)
			return 0;
		int top_right = 0;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> p[i].x >> p[i].y;		
		}
		for(int i = 1 ; i < n ; i++)
		{
			if(p[top_right] < p[i])
				top_right = i;
		}
		if(p[(top_right + 1 + n )%n].y < p[(top_right - 1 + n)%n].y)
			reverse(p,p+n);
		p[n].x = p[0].x;
		p[n].y = p[0].y;
		p[n+1].x = p[1].x;
		p[n+1].y = p[1].y;
		double maxtheta = -360,mintheta = 360;
		for(int i = 0 ; i < n ; i++)
		{
			point v1,v2;
			v1.x = p[i+1].x - p[i].x;
			v1.y = p[i+1].y - p[i].y;
			v2.x = p[i+2].x - p[i+1].x;
			v2.y = p[i+2].y - p[i+1].y;
			double l1 = len(v1);
			double l2 = len(v2);
			
			double cos = dot(v1,v2) / l1 / l2;
			double theta;
			if(cross(v1,v2)<0)
			{
				theta = 180.0 + fmod(acos(cos) * 180/pi + 180,180);
			}
			else
			{
				theta = 180.0 - fmod(acos(cos) * 180/pi + 180,180);
			}
			
			
			if(theta > maxtheta)
				maxtheta = theta;
			if(theta < mintheta)
				mintheta = theta;
		}
		cout << fixed << setprecision(6) << mintheta << " " << maxtheta << "\n";
	}
}
