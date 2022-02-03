#include <iostream> //DP
#include <vector>
using namespace std;

int dp[100005];

int main()
{
	int t,n,m,x,y;
	cin >> t;
	vector<char> v;
	for(int k = 0 ; k < t ; k++)
	{
		v.clear();
		v.push_back('*');
		cin >> n >> m >> x >> y;
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				char ch;
				cin >> ch;
				v.push_back(ch);
			}
			v.push_back('*');
		}
		int all = n * m + n;
		dp[0] = 0;
		if(v[1] == '.')
		{
			dp[1] = x;
		}
		else
		{
			dp[1] = 0;
		}
		for(int i = 2 ; i <= all; i++)
		{
			if(v[i] == '.' && v[i - 1] == '.')
			{
				dp[i] = min(dp[i - 1] + x,dp[i - 2] + y);
			}
			else if (v[i] == '.')
			{
				dp[i] = dp[i - 1] + x;
			}
			else
			{
				dp[i] = dp[i - 1];
			}
		}
		cout << dp[all] << "\n";
	}	
} 
