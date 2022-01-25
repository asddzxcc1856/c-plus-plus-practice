#include <iostream>
#include <cstring>
using namespace std;

char adj[105][105];
bool vis[105][105];
int mx[8] = {1,-1,0,0,1,-1,-1,1};
int my[8] = {0,0,1,-1,1,-1,1,-1};
int m,n;

void dfs(int x,int y)
{
	vis[x][y] = true;
	for(int i = 0 ; i < 8 ; i++)
	{
		int nx = x + mx[i];
		int ny = y + my[i];
		if((nx >= 0 && nx < m)&&(ny >= 0 && ny < n)&& adj[nx][ny] == '@' && vis[nx][ny] == false)
		{
			dfs(nx,ny);
		}
	}
}

int main ()
{
	
	while(cin >> m >> n,m,n)
	{
		for(int i = 0 ; i < m ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				cin >> adj[i][j];
			}
		}
		memset(vis,false,sizeof(vis));
		int ans = 0;
		for(int i = 0 ; i < m ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				if(adj[i][j] == '@' && vis[i][j] == false)
				{
					dfs(i,j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}
