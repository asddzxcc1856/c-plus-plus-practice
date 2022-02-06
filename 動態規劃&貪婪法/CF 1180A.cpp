#include <iostream>
using namespace std;

int main ()
{
	int dp[105];
	dp[1] = 1;
	for(int i = 2 ; i <= 100 ; i++)
		dp[i] = dp[i - 1] + ((i - 1) * 4);
	int n;
	cin >> n;
	cout << dp[n] << "\n"; 
	
}
