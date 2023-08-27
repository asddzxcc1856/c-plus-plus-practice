#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<string> s1,s2;
int dp[3005][3005];
int pre[3005][3005];
bool first;

void print_LCS(int i,int j)
{
	if(i == 0 || j == 0)
	{
		return;
	}
	else if (pre[i][j] == 0)
	{
		print_LCS(i - 1,j - 1);
		if(first == true)
		{
			cout << s1[i];
			first = false;
		}
		else
			cout << " " << s1[i];
	}
	else if (pre[i][j] == 1)
	{
		print_LCS(i - 1,j);
	}
	else if (pre[i][j] == 2)
	{
		print_LCS(i,j - 1);
	}
}

int main ()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string str;
	while(cin >> str)
	{
		s1.clear();
		s1.push_back("0");
		s1.push_back(str);
		while(cin >> str)
		{
			if(str != "#")
			{
				s1.push_back(str);
			}
			else
			{
				break;
			}
		}
		s2.clear();
		s2.push_back("0");
		while(cin >> str)
		{
			if(str != "#")
			{
				s2.push_back(str);
			}
			else
			{
				break;
			}
		}
		memset(dp,0,sizeof(dp));
		for(int i = 1 ; i < s1.size() ; i++)
		{
			for(int j = 1 ; j < s2.size() ; j++)
			{
				if(s1[i] == s2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					pre[i][j] = 0;
				}
				else
				{
					if(dp[i - 1][j] > dp[i][j - 1])
					{
						dp[i][j] = dp[i - 1][j];
						pre[i][j] = 1;
					}
					else
					{
						dp[i][j] = dp[i][j - 1];
						pre[i][j] = 2;
					}
				}
			}
		}
		first = true;
		print_LCS(s1.size() - 1,s2.size() - 1);
		cout << "\n";
	}
	
	
	
}