#include <iostream>
#include <sstream>
using namespace std;

int dp[105][205] = {};
int s[105],w[105];

int main ()
{
	int t;
	cin >> t;
	for(int g = 1 ; g <= t ; g++)
	{
		int len;
		cin >> len;
		
		s[0] = 0;
		int num = 1;
		string str;
		getline(cin,str);
		while(getline(cin,str))
		{
			if(str == "")
				break;
			stringstream ss(str);
			ss >> s[num] >> w[num];
			num++;
			if(s[num - 1] > len)
				num--;
		}
		num--;
		for(int i = 0 ; i <= num ; i++)
		{
			for(int j = 0 ; j <= 200 ; j++)
			{
				dp[i][j] = 100000000;
			}
		}
		dp[0][100] = 0;
		
		for(int i = 1 ; i <= num ; i++)
		{
			int l = s[i] - s[i - 1];
			for(int j = 0 ; j <= 200 ; j++)
			{
				for(int k = 0 ; k <= j ; k++)
				{
					if(j + l - k <= 200)
					{
						dp[i][j] = min(dp[i][j],dp[i - 1][j + l - k] + k * w[i]);
					}
				}
			}
		}
		if(len - s[num] > 100 || dp[num][100 + len - s[num]] == 100000000)
		{
			cout << "Impossible\n";
		}
		else
		{
			cout << dp[num][100 + len - s[num]] << "\n";
		}
		if(g != t)
			cout << "\n";
	}
}