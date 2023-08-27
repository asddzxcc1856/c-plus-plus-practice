#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

int n,k;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<pair<int,int>> v[605];
long long int dis[605];
bool vis[605];
int t[10];
int adj[10][105];
int len[10];

int main ()
{
	while(cin >> n >> k)
	{
		while(!pq.empty())
			pq.pop();
		for(int i = 0 ; i < 605 ; i++)
			v[i].clear();
		memset(vis,false,sizeof(vis));
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> t[i];	
		}
		string ls;
		getline(cin,ls);
		for(int i = 1 ; i <= n ; i++)
		{
			getline(cin,ls);
			stringstream ss(ls);
			int a;
			len[i] = 0;
			while(ss >> a)
			{
				adj[i][len[i]++] = a;
			}
		}
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 0 ; j < len[i] ; j++)
			{
				for(int k = j + 1 ; k < len[i] ; k++)
				{
					v[adj[i][j] + i * 100].push_back({adj[i][k] + 100 * i,t[i] * (adj[i][k] - adj[i][j])});	
					v[adj[i][k] + 100 * i].push_back({adj[i][j] + i * 100,t[i] * (adj[i][k] - adj[i][j])});
					//cout << v[adj[i][j] + i * 100].back().first << " " << v[adj[i][j] + i * 100].back().second << "\n";
				}
			}
			
		}
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = i + 1 ; j <= n ; j++)
			{
				for(int k = 0 ; k < 1 ; k++)
				{
						v[k + i * 100].push_back({k + 100 * j,0});
						v[k + 100 * j].push_back({k + i * 100,0});			
				}
			}
		}
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = i + 1 ; j <= n ; j++)
			{
				for(int k = 1 ; k < 100 ; k++)
				{
						v[k + i * 100].push_back({k + 100 * j,60});
						v[k + 100 * j].push_back({k + i * 100,60});			
				}
			}
		}
		for(int i = 0 ; i < 605 ; i++)
		{
			dis[i] = 1e12;
		}
		pq.push({0,100});
		dis[100] = 0; 
		
		while(!pq.empty())
		{
			int now = pq.top().second;
			pq.pop();
			if(vis[now] == true)
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
		long long int minn = 1e12;
		for(int i = 1 ; i <= n ; i++)
		{
			minn = min(dis[k + i * 100 ],minn);
		}
		if(minn != 1e12)
		{
			cout << minn << "\n";
		}
		else
		{
			cout << "IMPOSSIBLE\n";
		}
		/*
		for(int i = 0 ; i < 605 ; i++)
		{
			if(v[i].size() > 0)
			{
				cout << i << " : ";
			}
			for(int j = 0 ; j < v[i].size() ; j++)
			{
				cout << "b:" << v[i][j].first << " w:" << v[i][j].second << " ";
			}
			if(v[i].size() > 0)
				cout << "\n";
		}
		*/
	}
	
}