#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define N 100
#define M 50000
using namespace std;

int dp[N + 1][M + 1];
int w[N],v[N];

int main ()
{
	int t;
	cin >> t;
	for (int k = 0 ; k < t ; k++)
	{
		memset(dp,0,sizeof(dp));
		int m;
		cin >> m;
		int sum = 0;
		for (int i = 0 ; i < m ; i++)
		{
			cin >> w[i];
			v[i] = w[i];
			sum += w[i]; 
		}
		int all = sum;	
		sum /= 2;
		
		for (int i = 0 ; i < m ; i++)
		{
			for (int j = 0 ; j <= sum ; j++)
			{
				if(j < w[i])
				{
					dp[i + 1][j] = dp[i][j];
				}
				else
				{
					if(dp[i][j] < dp[i][j - w[i]] + v[i])
					{
						dp[i + 1][j] = dp[i][j - w[i]] + v[i];
					}
					else
					{
						dp[i + 1][j] = dp[i][j];
					}
				}
			}
		}
		cout << abs(all - dp[m][sum]*2)<< "\n"; 
	}	
} 
