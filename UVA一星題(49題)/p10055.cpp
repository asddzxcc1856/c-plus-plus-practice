#include <iostream>
#include <cmath>
using namespace std;

long long int a,b;

int main ()
{
	while(cin >> a >> b)
	{
		cout << (long long int)abs(b - a) << "\n";
	}

    return 0;
}

