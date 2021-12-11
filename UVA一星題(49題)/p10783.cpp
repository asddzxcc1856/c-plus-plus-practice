#include <iostream>
using namespace std;

int t,a,b,i,k,sum;

int main ()
{
	cin >> t;
	for (k = 1 ; k <= t ; k++)
	{
		cin >> a >> b;
		sum = 0;
		for(i = a ; i <= b ; i++)
		{
			if(i % 2 == 1)
			{
				sum += i;
			}
		}
		cout << "Case " << k << ": " << sum << "\n";
	}

    return 0;
}

