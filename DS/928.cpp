#include <iostream>
#include <queue>
#include <cstring>
#define clr(n,k) memset(n,k,sizeof(n))
using namespace std;

const int maxn = 305;
const int maxm = 3;

char adj[maxn][maxn];
bool vis[maxn][maxn][maxm];

int mx[3][4] = {{1,0,0,-1},{2,0,0,-2},{3,0,0,-3}};
int my[3][4] = {{0,1,-1,0},{0,2,-2,0},{0,3,-3,0}};
int sx,sy;
int t,m,n;

int bfs()
{
	queue<int> qx,qy,qd,qs;
	qx.push(sx);
	qy.push(sy);
	qd.push(0);
	qs.push(0);
	vis[sx][sy][0] = true;
	while(!qx.empty())
	{
		int x = qx.front();
		qx.pop();
		int y = qy.front();
		qy.pop();
		int d = qd.front();
		qd.pop();
		int s = qs.front();
		qs.pop();
		if(adj[x][y] == 'E')
		{
			return d;
		}
		for(int i = 0 ; i < 4 ; i++)
		{
			int nx = x + mx[s][i],ny = y + my[s][i],nd = d + 1,ns = (s + 1) % 3;
			if((nx >= 0 && nx < m) && (ny >= 0 && ny < n))
			{
				if(adj[nx][ny] == '.' || adj[nx][ny] == 'E' || adj[nx][ny] == 'S')
				{
					if(vis[nx][ny][ns] == false)
					{
						if(s == 0)
						{
							vis[nx][ny][ns] = true;
							qx.push(nx);
							qy.push(ny);
							qd.push(nd);
							qs.push(ns);
						}
						else if(s == 1 && adj[x + mx[0][i]][y + my[0][i]] != '#')
						{
							vis[nx][ny][ns] = true;
							qx.push(nx);
							qy.push(ny);
							qd.push(nd);
							qs.push(ns);
						}
						else if(s == 2 && adj[x + mx[0][i]][y + my[0][i]] != '#' && adj[x + mx[1][i]][y + my[1][i]] != '#')
						{
							vis[nx][ny][ns] = true;
							qx.push(nx);
							qy.push(ny);
							qd.push(nd);
							qs.push(ns);
						}
					}
				}
			}
		}
	}
	return -1;
}

int main ()
{
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		cin >> m >> n;
		for(int i = 0 ; i < m ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				cin >> adj[i][j];
				if(adj[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
			}
		}
		clr(vis,false);
		int ans = bfs();
		if(ans != -1)
			cout << ans << "\n";
		else
			cout << "NO\n";
	}
}
