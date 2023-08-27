#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[1005][1005];
vector<char> s1,s2;

int main ()
{
	string str1,str2;
	while(getline(cin,str1))
	{
		getline(cin,str2);
		s1.clear();
		s1.push_back('0');
		for(int i = 0 ; i < str1.length() ; i++)
		{
			s1.push_back(str1[i]);	
		}
		s2.clear();
		s2.push_back('0');
		for(int i = 0 ; i < str2.length() ; i++)
		{
			s2.push_back(str2[i]);	
		}
		memset(dp,0,sizeof(dp));
		for(int i = 1 ; i < s1.size() ; i++)
		{
			for(int j = 1 ; j < s2.size() ; j++)
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
		cout << dp[s1.size() - 1][s2.size() - 1] << "\n";
	}
	return 0;
}