#include <iostream>
using namespace std;

int main ()
{
	long long int dp[8000] = {};//要換的錢 
	dp[0] = 1;
	int w[5] = {1,5,10,25,50}; //幣值 
	for(int i = 0 ; i < 5 ; i++)
	{
		for (int j = w[i] ; j < 8000 ; j++)
		{
			dp[j] += dp[j - w[i]];//j 在考慮 i 種幣的情況下的組合方法數 = 
								  //j 在考慮 i - 1 種幣的情況下的組合方法數 +
								  //j - w[i] 在考慮 i 種幣的情況下的組合方法數 
		}
	}
	int n;
	while(cin >> n)
	{
		cout << dp[n] << "\n";
	}
}
