#include <iostream>
#include <iomanip>
using namespace std;

double a1x,a1y,a2x,a2y;
double x1,x2,x3,x4,y1,y2,y3,y4;
double q1x,q1y,q2x,q2y,q3x,q3y,q4x,q4y;

int main ()
{
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
	{
		if(x1 == x2 && y1 == y2)
		{
			swap(x1,x3);
			swap(y1,y3);
		}
		if(x1 == x3 && y1 == y3)
		{
			swap(x1,x2);
			swap(y1,y2);
		}
		if(x1 == x4 && y1 == y4)
		{
			swap(x1,x2);
			swap(y1,y2);
			swap(x4,x3);
			swap(y4,y3);
		}
		if(x2 == x4 && y2 == y4)
		{
			swap(x4,x3);
			swap(y4,y3);
		}
		if(x3 == x4 && y3 == y4)
		{
			swap(x4,x2);
			swap(y4,y2);
		}
		cout << fixed << setprecision(3) << x4 + x1 - x2 << " " << y4 + y1 - y2 << "\n";

	}

    return 0;
}

