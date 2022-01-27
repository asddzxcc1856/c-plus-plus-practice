#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int E,N,T;
vector<int> v[2505];
bool vis[2505];
int num,num2,source;
int maxn,maxni;

void bfs(int start)
{
	queue<int> q;
	queue<int> day;
	q.push(start);
	day.push(1);
	vis[start] = true;
	while(!q.empty())
	{
		int size = q.size();
		int t = 0;
		int nd,nx;
		while(size--)
		{
			nx = q.front();
			q.pop();
			nd = day.front();
			day.pop();
			for(int i = 0 ; i < v[nx].size() ; i++)
			{
				if(vis[v[nx][i]] == false)
				{
					vis[v[nx][i]] = true;
					q.push(v[nx][i]);
					day.push(nd + 1);
					t++;
				}
				
			} 
			
		}
		if(t > maxn)
		{
			maxn = t;
			maxni = nd;
		}
	}
}


int main ()
{
	cin >> E;
	for(int i = 0 ; i < E ; i++)
	{
		cin >> num;
		v[i].clear();
		for(int j = 0 ; j < num ; j++)
		{
			cin >> num2;
			v[i].push_back(num2);
		}	
	}
	cin >> T;
	for(int j = 0 ; j < T ; j++)
	{
		cin >> source;
		maxn = 0;
		maxni = 0;
		memset(vis,false,sizeof(vis));
		bfs(source);
		if(maxn == 0)
			cout << "0\n";
		else
			cout << maxn << " " << maxni << "\n";
	}
	
	
	return 0;
	
}
