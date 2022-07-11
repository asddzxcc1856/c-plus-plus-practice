#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int in[105];
vector<int> v[105];
int n,m;

void topological_ordering()
{
	queue<int> q;
	for(int i = 1 ; i <= n ; i++)
	{
		if(in[i] == 0)
		{
			q.push(i);
		}
	}
	for(int i = 0 ; i < n ; i++)
	{
		if(q.empty())
			break;
		
		int s = q.front();
		q.pop();
		in[s] = -1;
		
		if(i != n - 1)
			cout << s << " ";
		else
			cout << s << "\n";
		for(int j = 0 ; j < v[s].size() ; j++)
		{
			in[v[s][j]]--;
			if(in[v[s][j]] == 0)
			{
				q.push(v[s][j]);
			}
		}	
	}
}

int main ()
{
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0)
		{
			return 0;
		}
		memset(in,0,sizeof(in));
		for(int i = 1 ; i <= n ; i++)
			v[i].clear();
		for(int i = 0 ; i < m ; i++)
		{
			int s,e;
			cin >> s >> e;
			v[s].push_back(e);
		}
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 0 ; j < v[i].size(); j++)
			{
				in[v[i][j]]++;
			}
		}
		topological_ordering();
	}
}