#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int m,n;
char adj[55][55];
int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};
int adj2[55][55];
bool vis[55][55];
bool vis2[55][55];
int sum;
vector<int> num;
int dfs2(int x,int y,int s)
{
	vis2[x][y] = true;
	if(adj2[x][y] < s)
		s = adj2[x][y];
	for(int i = 0 ; i < 4 ; i++)
	{
		int nx = x + mx[i];
		int ny = y + my[i];
		if((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (adj[nx][ny] == 'X') && vis2[nx][ny] == false)
		{
			s = min(dfs2(nx,ny,s),s);
		}
	}
	return s;
}

void dfs(int x,int y)
{
	vis[x][y] = true;
	if(adj[x][y] == 'X')
	{
		bool have = false;
		int temp = sum + 1;
		for(int i = 0 ; i < 4 ; i++)
		{
			int nx = x + mx[i];
			int ny = y + my[i];
			if((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (adj[nx][ny] == 'X'))
			{
				memset(vis2,false,sizeof(vis2));
				temp = dfs2(nx,ny,sum + 1);
				if(temp < sum + 1)
				{
					have = true;
				}
			}
		}
		if(have == true)
		{
			adj2[x][y] = temp;
		}
		else
		{
			adj2[x][y] = temp;
			sum++;
		}
	}
	for(int i = 0 ; i < 4 ; i++)
	{
		int nx = x + mx[i];
		int ny = y + my[i];
		if((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (adj[nx][ny] == '*' || adj[nx][ny] == 'X') && vis[nx][ny] == false)
		{
			dfs(nx,ny);
		}
	}
}

int main ()
{
	int times = 1;
	while(cin >> m >> n)
	{
		if(m == 0 && n == 0)
		{
			return 0;
		}
		
		for (int i = 0; i < n ; i++)
		{
			for (int j = 0 ; j < m ; j++)
			{
				cin >> adj[i][j];
			}
		}
		num.clear();
		memset(vis,false,sizeof(vis));
		memset(adj2,1e6,sizeof(adj2));
		for (int i = 0; i < n ; i++)
		{
			for (int j = 0 ; j < m ; j++)
			{
				if((adj[i][j] == '*' || adj[i][j] == 'X') && vis[i][j] == false)
				{
					sum = 0;
					dfs(i,j);
					num.push_back(sum);
				}
			}
		}
		sort(num.begin(),num.end());
		cout << "Throw " << times++ << "\n";
		for (int i = 0 ; i < num.size() - 1 ; i++)
		{
			cout << num[i] << " ";
		}
		cout << num[num.size() - 1] << "\n";
		cout << "\n";
	}
}
