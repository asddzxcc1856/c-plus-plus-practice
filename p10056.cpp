#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int t,n,k,winner;
double p,q;
double a,r;

int main ()
{
	cin >> t;
	for(k = 0 ; k < t ; k++)
    {
    	cin >> n >> p >> winner;
    	q = 1 - p;
    	a = pow(q,winner - 1)*p;
    	r = pow(q,n);
    	if(p == 0)
    	{
    		cout << "0.0000\n";
		}
		else
		{
			cout << fixed << setprecision(4) << (a * (1 - pow(r,50))/(1-r)) << "\n";
		}
	}
	return 0;
}

