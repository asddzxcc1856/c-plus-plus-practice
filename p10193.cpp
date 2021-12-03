#include <iostream>
#include <algorithm>
using namespace std;

int n,i,j,k,sum1,sum2;
string str1,str2;

int main ()
{
	cin >> n;
	for (k = 1 ; k <= n ; k++)
	{
		cin >> str1 >> str2;
		sum1 = sum2 = 0;
		for (i = 0 ; i < str1.length() ; i++)
		{
			sum1 = sum1 * 2 + (str1[i] - '0');
		}
		for (i = 0 ; i < str2.length() ; i++)
		{
			sum2 = sum2 * 2 + (str2[i] - '0');
		}
		if(__gcd(sum1,sum2) == 1)
		{
			cout << "Pair #" << k << ":" << " Love is not all you need!\n";
		}
		else
		{
			cout << "Pair #" << k << ":" << " All you need is love!\n";
		}
	}

    return 0;
}

