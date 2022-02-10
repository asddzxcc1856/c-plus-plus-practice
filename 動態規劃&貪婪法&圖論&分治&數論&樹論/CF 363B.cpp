#include <iostream>
using namespace std;

int c[150005];

int main ()
{
	int n,k;
	cin >> n >> k;
	int sum = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> c[i];
		if(i <= k)
			sum += c[i];	
	}	
	int ans = 1,mn = sum;
	for(int i = k + 1 ; i <= n ; i++)
	{
		sum -= c[i - k];
		sum += c[i];
		if(mn > sum)
		{
			ans = i - k + 1;
			mn = sum;	
		}
	}
	cout << ans << "\n";

	return 0;
} 
