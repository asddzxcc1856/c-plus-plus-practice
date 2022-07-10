#include <iostream>
#include <vector>
using namespace std;



int main ()
{
	int n;
	cin >> n;
	cin.get();
	for(int k = 1 ; k <= n ; k++)
	{
		int dp[35][35] = {},f[35][35] = {};
		for(int i = 0 ; i <= 34 ; i++)
		{
			f[i][0] = 1;
			f[0][i] = 1;
		}
		vector<char> s1,s2;
		string str;
		getline(cin,str);
		s1.push_back('0');
		for(int i = 0 ; i < str.length() ; i++)
		{
			s1.push_back(str[i]);
		}
		getline(cin,str);
		s2.push_back('0');
		for(int i = 0 ; i < str.length() ; i++)
		{
			s2.push_back(str[i]);
		}
		for(int i = 1 ; i < s1.size() ; i++)
		{
			for(int j = 1 ; j < s2.size() ; j++)
			{
				if(s1[i] == s2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					f[i][j] = f[i - 1][j - 1];
				}
				else
				{
					if(dp[i - 1][j] > dp[i][j - 1])
					{
						dp[i][j] = dp[i - 1][j];
						f[i][j] = f[i - 1][j];
					}
					else if(dp[i - 1][j] < dp[i][j - 1])
					{
						dp[i][j] = dp[i][j - 1];
						f[i][j] = f[i][j - 1];
					}
					else
					{
						dp[i][j] = dp[i - 1][j];
						f[i][j] = f[i - 1][j] + f[i][j - 1];
					}
				}
			}
		}
		cout << "Case #" << k << ": " << s1.size() + s2.size() - dp[s1.size() - 1][s2.size() - 1] - 2 << " " << f[s1.size() - 1][s2.size() - 1] << "\n"; 
	}
}