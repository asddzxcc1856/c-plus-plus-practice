#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
	int n,a;
	cin >> n;
	for(int k = 0 ; k < n ; k++)
	{
		cin >> a;
		int b = 0;
		int y = 1;
		int temp = a;
		while(a != 0)
		{
			b = b + (a % 2 == 0 ? 1 : 0) * y; 
			a/=2;
			y*=2;
		}
		a = temp;
		if(b == 0)
		{
			b = 1;
			for(int i = 2 ; i * i <= a ; i++)
			{
				if(a % i == 0)
				{
					b = a/i;
					break;
				}
			}
		}
		cout << __gcd(a^b,a&b) << "\n"; 
	}
}
