#include <iostream>
using namespace std;

long long int c[2000005];

int main ()
{
	int t;
	cin >> t;
	for(long long int k = 0 ; k < t ; k++)
	{
		long long int n;
		cin >> n;
		for(long long int i = 0 ; i < n ; i++)
		{
			cin >> c[i];
		}
		long long int ans = 0;
		for(long long int i = 0 ; i < n ; i++)
		{
			for(long long int j = c[i] - i - 2 ; j < n ; j += c[i])
			{ 
				if(j <= i) continue;
				if(j + i + 2 == c[i] * c[j])
				{
					ans++;
				}
			}
		}
		cout << ans << "\n"; 
	}
		
} 
