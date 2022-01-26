#include <iostream>
#include <cstring>
#define m 25
#define n 30000
using namespace std;

int w[m],v[m];
int dp[n + 1];
int main ()
{
	
	memset(dp,0,sizeof(dp));
	
	int N,M;
	cin >> N >> M;
	for (int i = 0 ; i < M ; i++)
	{
		cin >> w[i] >> v[i];
	}
	for(int i = 0 ; i < M ; i++)
	{
		for (int j = N ; j >= w[i] ; j--)
		{
			dp[j] = max(dp[j],dp[j - w[i]] + v[i] * w[i]);
		}
	}
	cout << dp[N] << "\n";
}
