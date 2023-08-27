#include <iostream>
using namespace std;

int main ()
{
	int a,b,n;
	while(cin >> n,n)
	{
		int idx = 1;
		int exp = 0;
		a = b = 0;
		while(n != 0)
		{
			if(n % 2 == 1)
			{
				if(idx % 2 == 1)
				{
					a += (1 << exp);		
				}
				else
				{
					b += (1 << exp);
				}
				idx++;
			}
			exp++;
			n /= 2;
		}
		cout << a << " " << b << "\n";
	}
	
}
