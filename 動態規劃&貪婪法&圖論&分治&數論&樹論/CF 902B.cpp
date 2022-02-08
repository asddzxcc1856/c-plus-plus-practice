#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[10005];
int color[10005];
int color_now[10005];

void dfs(int now,int co)
{
	color_now[now] = co;
	for(int i = 0 ; i < v[now].size() ; i++)
	{		
		dfs(v[now][i],co);
	}
}

int main ()
{
	int t;
	cin >> t;
	for(int k = 2 ; k <= t ; k++)
	{
		int a;
		cin >> a;
		v[a].push_back(k);
	}
	for(int k = 1 ; k <= t ; k++)
	{
		cin >> color[k];
	}
	int ans = 0;
	memset(color_now,0,sizeof(color_now));
	for(int i = 1 ; i <= t ; i++ )
	{
		if(color_now[i] != color[i])
		{
			ans++;
			dfs(i,color[i]);
		}
			
	}
	
	cout << ans << "\n";
}
