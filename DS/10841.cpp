#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<pair<int,int>> v[5100];
bool vis[5100];
int dis[5100];
int n,k;
int t[55];
int adj[55][105];
int len[55];

int main ()
{
	while(cin >> n >> k)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> t[i];
		}	
		string str;
		getline(cin,str);
		memset(len,0,sizeof(len));
		for(int i = 1 ; i <= n ; i++)
		{
			getline(cin,str);
			stringstream ss(str);
			int num;
			while(ss >> num)
			{
				adj[i][len[i]++] = num;
			}
		}
		for(int i = 0 ; i < 5100 ; i++)
			v[i].clear();
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 0 ; j < len[i] ; j++)
			{
				for(int k = j + 1 ; k < len[i] ; k++ )
				{
					v[adj[i][j] + i * 100].push_back({adj[i][k] + i * 100,max(t[i] * (adj[i][len[i] - 1] - adj[i][j]) + t[i] * (adj[i][k] - adj[i][j]),t[i] * (adj[i][j] - adj[i][0]) + t[i] * (adj[i][k] - adj[i][j]))});
					v[adj[i][k] + i * 100].push_back({adj[i][j] + i * 100,max(t[i] * (adj[i][len[i] - 1] - adj[i][k]) + t[i] * (adj[i][k] - adj[i][j]),t[i] * (adj[i][k] - adj[i][0]) + t[i] * (adj[i][k] - adj[i][j]))});
				}
			}
		}
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = i + 1 ; j <= n ; j++)
			{
				for(int k = 0 ; k < 99 ; k++)
				{
					if(k != 0)
					{
						v[k + i * 100].push_back({k + j * 100,5});
						v[k + j * 100].push_back({k + i * 100,5});
					}
					else
					{
						v[k + i * 100].push_back({k + j * 100,0});
						v[k + j * 100].push_back({k + i * 100,0});
					}
				}
			}
		}
		for(int i = 0 ; i < 5100 ; i++)
		{
			dis[i] = 1e9;
		}
		while(!pq.empty())
			pq.pop();
		dis[100] = 0;
		pq.push({0,100});
		memset(vis,false,sizeof(vis));
		
		while(!pq.empty())
		{
			int now = pq.top().second;
			pq.pop();
			if(vis[now])
			{
				continue;
			}
			vis[now] = true;
			for(pair<int,int> nxt : v[now])
			{
				if(dis[nxt.first] > dis[now] + nxt.second)
				{
					dis[nxt.first] = dis[now] + nxt.second;
					pq.push({dis[nxt.first],nxt.first});
				}
			}
		}
		int minn = 1e9;
		for(int i = 1 ; i <= n ; i++)
		{
			minn = min(dis[k + i * 100],minn);
		}
		if(minn != 1e9)
		{
			cout << minn << "\n";
		}
		else
		{
			cout << "IMPOSSIBLE\n";
		}
	}	
}