#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int n,m;
	double mn = 1e9;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
	{
		double a,b;
		cin >> a >> b;
		if(a/b < mn)
			mn = a/b;
	}
	cout << fixed << setprecision(8) << mn * m << "\n";
}