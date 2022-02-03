#include <iostream>
#include <cstring>
#define m 25
#define n 30000
using namespace std;

int w[m],v[m];
int dp[m + 1][n + 1];
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
		for (int j = 0 ; j <= N ;j++)
		{
			if(j < w[i])
			{
				dp[i + 1][j] = dp[i][j];
			}
			else
			{
				dp[i + 1][j] = max(dp[i][j],dp[i][j - w[i]] + w[i] * v[i]);
			}
		}
	}
	cout << dp[M][N] << "\n";
}
