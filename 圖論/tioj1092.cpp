#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n,e;
vector<int> pre[10005];
int out[10005];
int winner[10005];
queue<int> q;

void toposort(int w)
{
	
	q.push(w);
	
	while(!(q.empty()))
	{
		int nx = q.front();
		q.pop();
		for(int i = 0 ; i < pre[nx].size() ; i++)
		{
			out[pre[nx][i]]--;
			if(winner[nx]==0)
				winner[pre[nx][i]] = 1;
			if(out[pre[nx][i]] == 0)
				q.push(pre[nx][i]);
		}
	}
}

int main()
{
	while(cin >> n >> e)
	{
		if(n == 0 && e == 0)
			break;
		
		memset(winner,0,sizeof(winner));
		memset(out,0,sizeof(out));
		for(int i = 0 ; i < n ; i++)
		{
			pre[i].clear();
		}
		for(int i = 0 ; i < e ; i++)
		{
			int a,b;
			cin >> a >> b;
			out[a-1]++;
			pre[b-1].push_back(a-1);
		}
		winner[n - 1] = 0;
		toposort(n - 1);
		string str;
		cin >> str;
		if(winner[0])
		{
			if(str == "Moumou")
				cout << "Mimi\n";
			else
				cout << "Moumou\n";
		}
		else
		{
			cout << str << "\n";
		}
	}
	return 0;
} 
