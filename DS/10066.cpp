#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[105][105];
vector<int> s1,s2;

int main ()
{
	int m,n,times = 1;
	while(cin >> m >> n)
	{
		if(m == 0 && n == 0)
		{
			return 0;
		}
		s1.clear();
		s1.push_back(0);
		for(int i = 0 ; i < m ; i++)
		{
			int a;
			cin >> a;
			s1.push_back(a);
		}
		s2.clear();
		s2.push_back(0);
		for(int i = 0 ; i < n ; i++)
		{
			int a;
			cin >> a;
			s2.push_back(a);
		}
		memset(dp,0,sizeof(dp));
		for(int i = 1 ; i <= m ; i++)
		{
			for(int j = 1 ; j <= n ;j++)
			{
				if(s1[i] == s2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
				}
			}
		}
		cout << "Twin Towers #" << times++ << "\n";
		cout << "Number of Tiles : " << dp[m][n] << "\n";
		cout << "\n";
	}
}