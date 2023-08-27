#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	int n,r,times = 1;
	while(cin >> n >> r)
	{
		if(n == 0 && r == 0)
		{
			return 0;
		}
		int dp[105][105];
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				dp[i][j] = -1e9;
			}
		}
		int s,e,w;
		for(int i = 0 ; i < r ; i++)
		{
			
			cin >> s >> e >> w;
			dp[s][e] = dp[e][s] = w;
		}
		for(int k = 1 ; k <= n ; k++)
		{
			for(int i = 1 ; i <= n ; i++)
			{
				for(int j = 1 ; j <= n ; j++)
				{
					if(dp[i][k] != -1e9 && dp[k][j] != -1e9)
					{
						dp[i][j] = max(dp[i][j],min(dp[i][k],dp[k][j]));
					}
				}
			}
		}
		cin >> s >> e >> w;
		cout << "Scenario #" << times++ << "\n";
		cout << "Minimum Number of Trips = " << ceil((double)w/(dp[s][e]-1)) << "\n\n";
	}
}