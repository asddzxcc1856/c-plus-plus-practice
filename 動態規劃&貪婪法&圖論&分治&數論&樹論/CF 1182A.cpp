#include <iostream>
using namespace std;

int main ()
{
	int n;
	int dp[65];
	dp[1] = 0;
	dp[2] = 2;
	for(int i = 3 ; i <= 60 ; i++)
	{
		if(i%2 == 0)
			dp[i] = dp[i - 2] * 2;
		else
			dp[i] = dp[i - 2];
	}
		
		
		
	cin >> n;
	cout << dp[n] << "\n";	
	
	
	return 0;
}
