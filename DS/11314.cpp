#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	for(int k = 1 ; k <= n ; k++)
	{
		double ax,ay,bx,by;
		cin >> ax >> ay >> bx >> by;
		bx = -bx;
		ay = -ay;
		cout << fixed << setprecision(3) << sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))+sqrt((ax+bx)*(ax+bx)+(-ay-by)*(-ay-by)) << "\n";
	}
}