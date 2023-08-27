#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int m[55];
int n[55];
int b[55];
int dp[55][55];
int main ()
{
	int num;
	cin >> num;
	
	for(int i = 1 ; i <= num ; i++)
	{
		cin >> m[i];
	}
	int c;
	while(cin >> c)
	{
		n[c] = m[1];
		for(int i = 2 ; i <= num ; i++)
		{
			cin >> c;
			n[c] = m[i];
		}
		for(int i = 1 ; i <= num ; i++)
		{
			b[i] = n[i];
		}
		sort(b+1,b+num + 1);
		memset(dp,0,sizeof(dp));
		for(int i = 1 ; i <= num ; i++)
		{
			for(int j = 1 ; j <= num ; j++)
			{
				if(b[i] == n[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
				}
			}
		}
		cout << dp[num][num] << "\n";
	}
	return 0;
}