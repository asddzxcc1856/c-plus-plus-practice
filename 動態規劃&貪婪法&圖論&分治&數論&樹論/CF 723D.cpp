#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct p{
	int area;
	int x;
	int y;
};

struct cmp{
	bool operator()(p a,p b){
		return a.area > b.area;
	}
};


int n,m,k;
char adj[55][55];
priority_queue<p,vector<p>,cmp > pq;
bool vis[55][55];
int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};
bool isocean;

void bfs(int x,int y,int *cnt)
{
	(*cnt)++;
	for(int i = 0 ; i < 4 ; i++)
	{
		int nx = x + mx[i];
		int ny = y + my[i];
		if((nx >= 0 && nx < n) && (ny >= 0 && ny < m))
		{
			if(adj[nx][ny] == '.' && vis[nx][ny] == false)
			{
				vis[nx][ny] = true;
				bfs(nx,ny,cnt);
			}
		}
		else
		{
			isocean = true;
		}
	}
}

void bfs2(int x,int y)
{
	adj[x][y] = '*';
	for(int i = 0 ; i < 4 ; i++)
	{
		int nx = x + mx[i];
		int ny = y + my[i];
		if((nx >= 0 && nx < n) && (ny >= 0 && ny < m))
		{
			if(adj[nx][ny] == '.')
			{

				bfs2(nx,ny);
			}
		}
	}
}

int main ()
{
	
	cin >> n >> m >> k;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			cin >> adj[i][j]; 	
		}	
	}	
	memset(vis,false,sizeof(vis));
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if(adj[i][j] == '.' && vis[i][j] == false)
			{
				isocean = false;
				p temp;
				temp.area = 0;
				temp.x = i;
				temp.y = j;
				vis[i][j] = true;
				bfs(i,j,&temp.area);
				if(isocean == false)
					pq.push(temp);
			}	
		}	
	}
	int ans = 0;
	while(pq.size() != k)
	{
		bfs2(pq.top().x,pq.top().y);
		ans += pq.top().area; 
		pq.pop();
	}
	cout << ans << "\n";
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			cout << adj[i][j]; 	
		}	
		cout << "\n";
	}	
} 
