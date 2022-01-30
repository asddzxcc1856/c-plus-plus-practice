#include <iostream>
#include <cstring>
using namespace std;

int m,n;
int dp[105][105];
int adj[105][105];
int w[105][105],h[105][105];

int main ()
{
	while(cin >> m >> n)
	{
		if(m == 0 && n == 0)
		{
			return 0;
		}
		memset(dp,0,sizeof(dp));
		memset(adj,0,sizeof(adj));
		memset(w,0,sizeof(w));
		memset(h,0,sizeof(h));
		for(int i = 1 ; i <= m ; i++)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				cin >> adj[i][j];
				if(adj[i][j] == 0)
					w[i][j] = w[i][j - 1] + 1;
				else 
					w[i][j] = 0;
					
				if(adj[i][j] == 0)
					h[i][j] = h[i - 1][j] + 1;
				else
					h[i][j] = 0; 
			}	
		}
		int ans = 0;
		for(int i = 1 ; i <= m ; i++)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				if(adj[i][j] == 1)
					continue;
				int t1 = 2147483647,t2 = 2147483647;
				for(int q = j ; q > j - w[i][j] ; q--)
				{
					t1 = min(t1,h[i][q]);
				}
				for(int q = i ; q > i - h[i][j] ; q--)
				{
					t2 = min(t2,w[q][j]);
				}
				int temp = t1 * t2;
				if(ans < temp)
				{
					ans = temp;
				}
			}
			
		}
		cout << ans << "\n";
	}
} 
