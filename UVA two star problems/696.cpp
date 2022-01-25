#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	int m,n,c;
	while(cin >> m >> n)
	{
		if(m == 0 && n == 0)
			return 0;
		int ans;
		if(m == 1)
		{
			ans = n;
		}
		else if (n == 1)
		{
			ans = m;
		}
		else if(m == 2)
		{
			int c = n%4;
			if(c)
			{
				ans = (n/4) * 4 + (c > 1 ? 4 : 2);
			} 
			else
			{
				ans = (n/4) * 4;
			}
		}
		else if (n == 2)
		{
			int c = m%4;
			if(c)
			{
				ans = (m/4) * 4 + (c > 1 ? 4 : 2);
			} 
			else
			{
				ans = (m/4) * 4;
			}
		}
		else
		{
			ans = (m * n + 1) / 2;
		}
		cout << ans <<" knights may be placed on a " << m << " row " << n << " column board.\n";
	}
}
