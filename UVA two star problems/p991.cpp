#include <iostream>
using namespace std;

int main ()
{
	int dp[15] = {};
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2 ; i < 11 ; i++)
	{
		for(int j = 0 ; j < i ; j++)
			dp[i] = dp[i] + dp[j]*dp[i - j - 1];
	}	
	int n;
	int times = 0;
	while(cin >> n)
	{
		if(times != 0)
			cout << "\n";
		cout << dp[n] << "\n";
		times++;
	}
} 
