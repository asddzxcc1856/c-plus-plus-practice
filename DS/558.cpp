#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAXN 1005
using namespace std;

vector<pair<int,int>> v[MAXN];
queue<int> q;
int vis[MAXN];
int dis[MAXN];
bool inqueue[MAXN];

int main ()
{
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		int n,m;
		cin >> n >> m;
		for(int i = 0 ; i < MAXN ; i++)
		{
			v[i].clear();
		}
		for(int i = 0 ; i < m ; i++)
		{
			int start,end,weight;
			cin >> start >> end >> weight;
			v[start].push_back({end,weight});
		}
		for(int i = 0 ; i < MAXN ; i++)
		{
			dis[i] = 2147483647;
		}
		dis[0] = 0;
		while(!q.empty())
		{
			q.pop();
		}
		q.push(0);
		bool flag = true;
		memset(vis,0,sizeof(vis));
		memset(inqueue,false,sizeof(inqueue));
		vis[0]++;
		while(!q.empty())
		{
			int now = q.front();
			q.pop();
			
			inqueue[now] = false;
			for(pair<int,int> p : v[now])
			{
				if(dis[p.first] > dis[now] + p.second)
				{
					dis[p.first] = dis[now] + p.second;
					if(inqueue[p.first] == false)
					{
						q.push(p.first);
						inqueue[p.first] = true;
						vis[p.first]++;
						if(vis[p.first] > (n - 1))
						{
							flag = false;
							break;
						}
					}
				}
			}
			if(flag == false)
			{
				break;
			}
		}
		if(flag)
		{
			cout << "not possible\n";
		}
		else
		{
			cout << "possible\n";
		}
	}
	
	return 0;
}