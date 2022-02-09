#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

int c[500005];
int dp[500005][6];
int main ()
{
	int t;
	cin >> t;
	for(int i = 0 ; i < t ; i++)
	{
		cin >> c[i];
	}
	int ans = 0;
	map<int,int> ma;
	queue<int> q[45];
	ma[4] = 0; ma[8] = 1; ma[15] = 2; ma[16] = 3; ma[23] = 4; ma[42] = 5; 
	int num[6] = {4,8,15,16,23,42};
	int cnt = 0;
	memset(dp,0,sizeof(dp));
 	for(int i = 0 ; i < t ; i++)
	{
		dp[i][ma[c[i]]]++;
		q[c[i]].push(i);
		if(q[4].size() > 0 && q[8].size() > 0 && q[15].size() > 0 && q[16].size() > 0 && q[23].size() > 0 && q[42].size() > 0 && q[4].front() < q[8].front() && q[8].front() < q[15].front() && q[15].front() < q[16].front() && q[16].front() < q[23].front() && q[23].front() < q[42].front() && dp[i][0] >= 1 && dp[i][1] >= 1 && dp[i][2] >= 1 && dp[i][3] >= 1 && dp[i][4] >= 1 && dp[i][5] >= 1)
		{
			for(int j = 0 ; j < 6 ; j++)
			{
				dp[i][j]--;			
			}
			q[4].pop();
			q[8].pop();
			q[15].pop();
			q[16].pop();
			q[23].pop();
			q[42].pop();
		}	
		
		for(int j = 5 ; j >= 1 ; j--)
		{
			for(int k = 0 ; k < j ; k++)
			{
				while(q[num[k]].size() > 0 && q[num[j]].size() > 0 && q[num[j]].front() < q[num[k]].front())
				{
					ans++;
					dp[i][j]--;
					q[num[j]].pop();
				}	
			}
		}
		for(int j = 0 ; j < 6 ; j++)
		{
			dp[i + 1][j] = dp[i][j];
		}
	}
	for(int j = 0 ; j < 6 ; j++)
	{
		ans += dp[t][j];
	}
	cout << ans << "\n";
} 
