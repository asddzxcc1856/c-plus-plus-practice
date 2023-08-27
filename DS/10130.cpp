#include <iostream>
#include <cstring>
using namespace std;

int p[1005],w[1005];
int dp[1005][35];

int main ()
{
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		int n;
		cin >> n;
		
		//input p[] w[]
		for(int i = 0 ; i < n ; i++)
		{
			cin >> p[i] >> w[i];
		}

		//0/1 knapsack
		int g,ans = 0;
		cin >> g;
		for(int q = 0 ; q < g ; q++)
		{
			int W;
			cin >> W;
			memset(dp,0,sizeof(dp));
			for(int i = 0 ; i < n ; i++)
			{
				for(int j = 0 ; j <= W ; j++ )
				{
					if(j - w[i] < 0)
					{
						dp[i + 1][j] = dp[i][j];	
					}
					else
					{
						dp[i + 1][j] = max(dp[i][j],dp[i][j - w[i]] + p[i]);
					}
				}	
			}
			ans += dp[n][W];
		}
		cout << ans << "\n";
		
	}
}