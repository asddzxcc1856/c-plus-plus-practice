#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> p;
vector<int> pr[1005];
int dis[1005];
bool vis[1005];

bool isp(int n)
{
	if(n == 2)
		return true;
	else
	{
		for(int i = 2 ; i * i <= n ; i++)
		{
			if(n % i == 0)
				return false;
		}
	}
	return true;
}

int BFS(int sx,int sy)
{
	queue<int> q;
	q.push(sx);
	vis[sx] = true;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		if(x == sy)
		{
			return dis[x];
		}
		for(int nx : pr[x])
		{
			if(nx <= sy && vis[nx] == false)
			{
				vis[nx] = true;
				q.push(nx);
				dis[nx] = dis[x] + 1;
			}
				
		}
	}
	return -1;
}



int main ()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 2 ; i <= 500 ; i++)
	{
		if(isp(i))
			p.push_back(i);	
	}
	for(int i = 1 ; i < 1000 ; i++)
	{
		for(int j = 0 ; j < p.size() && p[j] < i; j++)
		{
			if (i % p[j] == 0)
			{
				pr[i].push_back(i + p[j]);
			}
		}
	}
	
	int m,n,times = 1;
	while(cin >> m >> n)
	{
		if(m == 0 && n == 0)
		{
			return 0;
		}
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		cout << "Case " << times++ << ": " << BFS(m,n) << "\n";
	}
}