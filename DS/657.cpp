#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};
char adj[55][55];
bool vis[55][55],vis2[55][55];
int m,n,ans;

void dfs2(int nx,int ny)
{
	vis2[nx][ny] = true;
	for(int i = 0 ; i < 4 ; i++)
	{
		int nnx = nx + mx[i],nny = ny + my[i];
		if((nnx >= 0 && nnx < n) && (nny >= 0 && nny < m))
		{
			if(vis2[nnx][nny] == false && adj[nnx][nny] == 'X')
			{
				dfs2(nnx,nny);
			}
		}
	}
}

void dfs(int nx,int ny)
{
	vis[nx][ny] = true;
	for(int i = 0 ; i < 4 ; i++)
	{
		int nnx = nx + mx[i],nny = ny + my[i];
		if((nnx >= 0 && nnx < n) && (nny >= 0 && nny < m))
		{
			if(vis[nnx][nny] == false && (adj[nnx][nny] == '*' || adj[nnx][nny] == 'X'))
			{
				if(vis2[nnx][nny] == false && adj[nnx][nny] == 'X')
				{
					ans++;
					dfs2(nnx,nny);
				}
				dfs(nnx,nny);
			}
		}
	}
}

int main ()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int times = 1;
	while(cin >> m >> n)
	{
		if(m == 0 && n == 0)
			return 0;
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				cin >> adj[i][j];
			}
		}
		
		memset(vis,false,sizeof(vis));
		memset(vis2,false,sizeof(vis2));
		vector<int> v;
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				if(vis[i][j] == false && (adj[i][j] == '*' || adj[i][j] == 'X'))
				{
					ans = 0;
					if(vis2[i][j] == false&& adj[i][j] == 'X')
					{
						ans++;
						dfs2(i,j);
					}
					dfs(i,j);
					v.push_back(ans);
				}
			}
		}
		
		sort(v.begin(),v.end());
		cout << "Throw " << times++ << "\n"; 
		for(int i = 0 ; i < v.size() - 1 ; i++)
		{
			cout << v[i] << " ";
		}
		cout << v[v.size() - 1] << "\n";
		cout << "\n";
	}
	
}