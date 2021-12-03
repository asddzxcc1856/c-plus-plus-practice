#include <iostream>
using namespace std;

long long int t,a,b,i,k,aa1,aa2,bb1,bb2;

int main ()
{
	cin >> t;
	for (k = 1 ; k <= t ; k++)
	{
		cin >> a >> b;
		aa1 = (a+b)/2;
		bb1 = (a-aa1);
		aa2 = (a-b)/2;
		bb2 = (a-aa2);
		if(a >= b && aa1 == bb2 && bb1 == aa2 && aa1 >= 0 && bb1 >= 0 && bb2 >= 0 && aa2 >= 0)
		{
			cout << aa1 << " " << bb1 << "\n";
		}
		else
		{
			cout << "impossible\n";
		}
	}

    return 0;
}

