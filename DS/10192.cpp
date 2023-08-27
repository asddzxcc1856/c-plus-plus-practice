#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<char> s1,s2;
int dp[105][105];

int main ()
{
	int times = 1;
	string str;
	while(getline(cin,str))
	{
		if(str == "#")
		{
			return 0;
		}
		s1.clear();
		s1.push_back('0');
		for(int i = 0 ; i < str.length() ; i++)
		{
			s1.push_back(str[i]);
		}
		s2.clear();
		s2.push_back('0');
		getline(cin,str);
		for(int i = 0 ; i < str.length() ; i++)
		{
			s2.push_back(str[i]);
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
		cout << "Case #" << times++ << ": you can visit at most " << dp[s1.size() - 1][s2.size() - 1] << " cities.\n";
	}
	
}