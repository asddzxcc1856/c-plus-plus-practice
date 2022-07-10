#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> p;
vector<pair<int,int>> pr[1005];
int dp[1005][1005];

bool isp(int n)
{
	if(n == 2)
		return true;
	else
	{
		for(int i = 2 ; i * i <= n ; i++)
		{
			if(n % i == 0)
				return false;
		}
	}
	return true;
}



int main ()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 2 ; i <= 1000 ; i++)
	{
		if(isp(i))
			p.push_back(i);	
	}
	for(int i = 0 ; i < 1005 ; i++)
	{
		for(int j = 0 ; j < 1005 ; j++)
		{
			dp[i][j] = 1e9;
		}
	}
	for(int i = 1 ; i <= 1000 ; i++)
	{
		dp[i][i] = 0;
		for(int j = 0 ; j < p.size() && p[j] < i; j++)
		{
			if (i % p[j] == 0)
			{
				dp[i][i + p[j]] = 1;
			}
		}
	}
	for(int k = 2 ; k < 1000 ; k++)
	{
		for(int i = 1 ; i < k - 1; i++)
		{
			for(int j = k ; j <= 1000 ; j++)
			{
				if(dp[i][k] != 1e9 && dp[k][j] != 1e9)
					dp[i][j] = min(dp[i][k] + dp[k][j],dp[i][j]);
			}
		}
	}
	
	int m,n,times = 1;
	while(cin >> m >> n)
	{
		if(m == 0 && n == 0)
		{
			return 0;
		}
		if(dp[m][n] != 1000000000)
			cout << "Case " << times++ << ": " << dp[m][n] << "\n";
		else
			cout << "Case " << times++ << ": " << -1 << "\n";
	}
}