#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

struct point{
	double x;
	double y;
};

struct Vector{
	double x;
	double y;
};

double length(point a, point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dot(point o, point a, point b)
{
	Vector v1 = {a.x - o.x,a.y - o.y};
	Vector v2 = {b.x - o.x,b.y - o.y};
	
	return v1.x * v2.x + v1.y * v2.y;
}

double cross(point o, point a, point b)
{
	Vector v1 = {a.x - o.x,a.y - o.y};
	Vector v2 = {b.x - o.x,b.y - o.y};
	
	return v1.x * v2.y - v1.y * v2.x;
}

double sin_cos(point o, point a, point b)
{
	double l1 = length(o,a);
	double l2 = length(o,b);
	
	
	double costheta = dot(o,a,b) / l1 / l2;
	double ctheta = acos(costheta);
	
	return ctheta;
}

int main()
{
	int n;
	while(cin >> n)
	{
		if(n < 3)
			return 0;
		point p[25];
		for(int i = 0 ; i < n ; i++)
		{
			cin >> p[i].x >> p[i].y;
		}
		double sum = 0;
		for(int i = 0 ; i < n ; i++)
		{
			point a = {p[i].x,p[i].y};
			point b = {p[(i + 1)%n].x,p[(i + 1)%n].y};
			sum  += cross({0,0},a,b);
		}
		sum /= 2.0;
		if(sum <= 0)
			reverse(p,p+n);
		double minn = 360;
		double maxn = 0;
		for(int i = 0 ; i < n ; i++)
		{
			point a = {p[i].x,p[i].y};
			point b = {p[(i + 1)%n].x,p[(i + 1)%n].y};
			point c = {p[(i + 2)%n].x,p[(i + 2)%n].y};
			double ret = sin_cos(b,a,c) * 180 / acos(-1.0);
			
			if(cross(a,b,c) < 0) ret  = (double)360.0 - ret;
			minn = min(ret,minn);
			maxn = max(ret,maxn);
		}
		cout << fixed << setprecision(6) << minn << " " << maxn << "\n";
	}
}