#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int node = 100005;
vector<int> v[node];
vector<int> ans;
bool vis[node];


void init()
{
	memset(vis,false,sizeof(vis));
}

void bfs(int s)
{
	init();
	priority_queue<int,vector<int>,greater<int> > pq;
	pq.push(s);
	vis[s] = true;
	while(!pq.empty())
	{
		auto now = pq.top();
		pq.pop();
		ans.push_back(now);
		for(auto nx : v[now])
		{
			if(vis[nx] == false)
			{
				vis[nx] = true;
				pq.push(nx);
				
			}
		}
	}
}


int main ()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++)
	{
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	bfs(1);
	
	for(int i = 0 ; i < ans.size() - 1 ; i++)
	{
		cout << ans[i] << " ";
	}
	cout << ans[ans.size() - 1] << "\n";
	
	return 0;
}
