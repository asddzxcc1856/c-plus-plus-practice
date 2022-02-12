#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long int c[100005];
const long long int INF = 1e17;

long long int mul(long long int a,long long int b)
{
	return (INF / a > b ? a * b : INF);
}

long long int add(long long int a,long long int b)
{
	return (INF <= a + b ? INF : a + b);
}

int main ()
{
	long long int n;
	cin >> n;
	long long int sum = 0;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> c[i];
		sum += abs(c[i] - 1);
	}
	sort(c,c+n);
	if(n <= 2)
	{
		cout << c[0] - 1 << "\n";
	}
	else
	{
		long long int ans = sum;
		for(int x = 1 ; ;x++)
		{
			long long int curpow = 1,curcost = 0;
			for(int i = 0 ; i < n ; i++)
			{
				curcost = add(curcost,abs(c[i] - curpow));
				curpow = mul(curpow,x);
			}
			if(curpow == INF || curpow / x > ans + c[n - 1] )break;
			ans = min(ans,curcost);
		}	
		cout << ans << "\n";
	}
	
	return 0;
	
}
