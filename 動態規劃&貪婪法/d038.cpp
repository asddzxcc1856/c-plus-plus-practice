#include <iostream>
using namespace std;

int main ()
{
	long long int dp[51];
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3 ; i <= 50 ; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	int n;
	while(cin >> n,n)
	{
		cout << dp[n] << "\n"; 
	}
}
