#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	bool ok = true;
	unsigned long long int n;
	unsigned long long int cnt = 1,mx = 0,mn = 20,temp;
	cin >> n;
	if(n <= 1)
	{
		cout << n << " 0\n";
	}
	else
	{
		for(int i = 2 ; i * i <= n ; i++)
		{
			if(n % i == 0)
			{
				cnt *= i;
				temp = 0;
				while(n % i == 0)
				{
					n/=i;
					temp++;
				}
				mx = max(mx,temp);
				mn = min(mn,temp);
			}
		}
		if(n > 1)
		{
			cnt *= n;
			mx = max(1ull,mx);
			mn = min(1ull,mn);
		}
		int t = ceil(log2(mx)) + 1e-8;
		if(mx == mn && (1 << t) == mx)
		{
			cout << cnt << " " << t << "\n";
		}
		else
		{
			cout << cnt << " " << t + 1 << "\n";
		}	
	}
	
	
	return 0;
} 
