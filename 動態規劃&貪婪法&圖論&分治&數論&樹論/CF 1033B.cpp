#include <iostream>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	for(int k = 0 ; k < n ; k++)
	{
		long long int a,b;
		cin >> a >> b;
		if(a - b == 1)
		{
			long long int sum = a + b;
			bool p = true;
			for(long long int i = 2 ; i * i <= sum ; i++)
			{
				if(sum % i == 0)
				{
					p = false;
				}
			}
			if(p)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}