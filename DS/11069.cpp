#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	int n;
	int dp[80];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	for(int i = 4 ; i <= 76 ; i++)
	{
		dp[i] = dp[ i - 2 ] + dp[ i - 3 ];
	}
	while(cin >> n)
	{
		cout << dp[n] << "\n";
	}
}