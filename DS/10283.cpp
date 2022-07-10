#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double R;
double pi = acos(-1.0);
double N;

int main ()
{
	while(cin >> R >> N)
	{
		if(N == 1)
		{
			double I,E;
			I = E = 0.0;
			cout << fixed << setprecision(10) << R << " " << I << " " << E << "\n";
			continue;
		}
		double NN = N;
		double r = R * sin(pi/NN)/(1+sin(pi/NN));
		
		double I = (N * r * r / tan(pi/N) - r * r * pi *((NN - 2)/2));
		double A = R * R * pi;
		
		double E = N * r * r * pi;
		cout << fixed << setprecision(10) << r  << " " << I << " " << A - I - E << "\n";
	}
}