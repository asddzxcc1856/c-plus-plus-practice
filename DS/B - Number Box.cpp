#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct point{
	int w;
	int x;
	int y;
};

char adj[15][15];
long long int adj2[11];
point adj3[105];
bool vis[15][15];
int n;
long long int sum,ans;
vector<char> sum2,ans2;
int mx[8] = {-1,-1,-1,0,0,1,1,1};
int my[8] = {-1,0,1,-1,1,-1,0,1};
vector<char> v;

void dfs(int dep,int x,int y,long long int s,vector<char>& ve,int k)
{
	
	if(dep == n)
	{
		if(s > sum)
		{
			sum = s;
			sum2.clear();
			for(int i = 0 ; i < ve.size() ; i++)
			{
				sum2.push_back(ve[i]);
			}
			
		}
		return;
	}
	if(adj2[dep] > s)
	{
		return;
	}
	else
	{
		adj2[dep] = s;
	}
	int nx = (x + mx[k])%n,ny = (y + my[k])%n;
	if(nx < 0) nx+=n;
	if(ny < 0) ny+=n;
	if(vis[nx][ny] == false)
	{	
		ve.push_back(adj[nx][ny]);
		vis[nx][ny] = true;
		dfs(dep + 1,nx,ny,s * 10 + (long long int)(adj[nx][ny] - '0'),ve,k);
		vis[nx][ny] = false;
		ve.pop_back();
	}
}

bool cmp(point a,point b)
{
	return a.w > b.w;
}

int main ()
{
	cin >> n;
	int len = 0;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			cin >> adj[i][j];
			adj3[len].w = adj[i][j];
			adj3[len].x = i;
			adj3[len++].y = j;
		}
	}
	sort(adj3,adj3+n*n,cmp);
	ans = 0;	
	sum = 0;
	memset(adj2,0,sizeof(adj2));
    int ti = adj3[0].w - '0';
    if(ti == 1)
    {
		ans2.clear();
		for(int j = 0 ; j < n ; j++)
		{
			ans2.push_back('1');
		}
	}
	else
	{
		for(int i = 0 ; i < n * n && adj3[i].w - '0' ==ti ; i++)
		{
			for(int k = 0 ; k < 8 ; k++)
			{
				vis[adj3[i].x][adj3[i].y] = true;
				v.push_back(adj[adj3[i].x][adj3[i].y]);
				dfs(1,adj3[i].x,adj3[i].y,adj[adj3[i].x][adj3[i].y] - '0',v,k);
				v.pop_back();
				vis[adj3[i].x][adj3[i].y] = false;
				if(sum > ans)
				{
					ans = sum;
					ans2.clear();
					for(int j = 0 ; j < sum2.size() ; j++)
					{
						ans2.push_back(sum2[j]);
					}
				}
			}
		}
	}
	
	
	for(int i = 0 ; i < ans2.size() ; i++)
	{
		cout << ans2[i];
	}
	cout << "\n";
	
	return 0;
}