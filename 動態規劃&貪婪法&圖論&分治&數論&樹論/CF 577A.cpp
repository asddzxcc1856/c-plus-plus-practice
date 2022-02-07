#include <iostream>
using namespace std;

int main ()
{
	int n,x,ans = 0;
	cin >> n >> x;
	for(int i = 1 ; i * i <= x && i <= n; i++)
	{
		if(x % i == 0)
		{
			int j = x / i;
			if(j <= n)
			{
				if(j != i)
				{
					ans += 2;
				}	
				else
				{
					ans += 1;
				}	
			}
		}	
	}	
	cout << ans << "\n";
} 
