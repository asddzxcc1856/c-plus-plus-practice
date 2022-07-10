#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
	long long int n;
	long long int times = 1;
	while(cin >> n)
	{
		if(n == 0)
			return 0;
			
		long long int ans = 0;
		long long int tmp = n;
		long long int base = 1;
		long long int t = 0;
		for(long long int i = 2 ; i * i <= n ; i++)
		{
			base = 1;
			while(tmp%i == 0 )
			{
				tmp/=i;
				base *= i;
				
			}		
			if(base != 1)
			{
				t++;
				ans += base;	
			}
		}
		if(tmp > 1)
		{
			ans += tmp;
			t++;
		}
		if(n == 1)
		{
			cout << "Case " << times++ << ": " << 2 << "\n";
		}
		else if(ans == 0)
		{
			cout << "Case " << times++ << ": " << n + 1 << "\n";
		}
		else
		{
			if(t == 1 || ans == n)
			{
				ans += 1;
			}
			cout << "Case " << times++ << ": " << ans << "\n";
		}
		
	}
}