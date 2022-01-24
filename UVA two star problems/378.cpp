#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	cout << "INTERSECTING LINES OUTPUT\n";
	for (int k = 0 ; k < n ; k++)
	{
		double x1,y1,x2,y2,x3,y3,x4,y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		int nm1 = 0,nm2 = 0;
		double m1 = (y1-y2)/(x1-x2);
		double m2 = (y3-y4)/(x3-x4);
		double b1 = -10000,b2 = -30000;
		if (fabs(x1 - x2) < 1e-15) 
		{
			nm1 = 1;
			m1 = 1e-6;
		}
		else
		{
			b1 = y1 - m1*x1;
		}
		if (fabs(x3 - x4) < 1e-15)
		{
			nm2 = 1;
			m2 = 1e-6;
		}
		else
		{
			b2 = y3 - m2*x3;
		}
		//y = mx +b;
		//b = y - mx;
		if((m1 == m2) || (nm2 == 1 && nm1 == 1))
		{
			
			if((b1 == b2) || (nm2 == 1 && nm1 == 1 && x1 == x3))
				cout << "LINE\n";
			else
				cout << "NONE\n";	
		} 
		else
		{
			//cout << m1 << " " << m2 << " " << b1 << " " << b2 << "\n"; 
			//y - m1x = b1 --1
			//y - m2x = b2 --2
			//(-m1 + m2)x = b1 - b2
			//x = (b1 - b2)/(-m1 + m2)
			double sx,sy;
			if(nm1 == 1)
			{
				sx = x1;
				sy = m2*sx + b2;
			}
			else if (nm2 == 1)
			{
				sx = x3;
				sy = m1*sx + b1;
			}
			else
			{
				sx = (b1 - b2)/(-m1 + m2);
				sy = m1*sx + b1;
			}
			
			cout << "POINT " << fixed << setprecision(2) << sx << " " << sy << "\n";	
		}
	}	
	cout << "END OF OUTPUT\n";
} 
