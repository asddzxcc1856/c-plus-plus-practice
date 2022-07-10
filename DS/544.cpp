#include <iostream>
#include <map>
using namespace std;

int n,m;
int dp[205][205];

int main ()
{
	int times = 1;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0)
		{
			return 0;
		}
		map<string,int> ma;
		int len = 0;
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				dp[i][j] = -1e9;
			}
		} 
		string s,e;
		for(int i = 0 ; i < m ; i++)
		{
			
			int w;
			cin >> s >> e >> w;
			if(ma.find(s) == ma.end())
			{
				ma[s] = len++;	
			}	
			if(ma.find(e) == ma.end())
			{
				ma[e] = len++;
			}
			dp[ma[s]][ma[e]] = max(dp[ma[s]][ma[e]],w);
			dp[ma[e]][ma[s]] = max(dp[ma[e]][ma[s]],w);
		}
		for(int k = 0 ; k < n ; k++)
		{
			for(int i = 0 ; i < n ; i++)
			{
				for(int j = 0 ; j < n ; j++)
				{
					if(dp[i][k] != -1e9 && dp[k][j] != -1e9)
					{
						dp[i][j] = max(dp[i][j],min(dp[i][k],dp[k][j]));
					}
				}
			}
		}
		cin >> s >> e;
		cout << "Scenario #" << times++ << "\n";
		cout << dp[ma[s]][ma[e]] << " tons\n\n";
	}
}