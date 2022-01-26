#include <iostream>
#include <cstring>
using namespace std;

int t;
int m,n,sx,sy;
int adj[105][105];
bool vis[105][105];
int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};
int cnt;
string str;

void dfs(int x,int y)
{
	if(adj[x][y] == 0)
		cnt++;
	vis[x][y] = true;
	for(int i = 0 ; i < 4 ; i++)
	{
		int nx = x + mx[i];
		int ny = y + my[i];
		if((nx >= 0 && nx < m) && (ny >= 0 && ny < n) && adj[nx][ny] == 0 && vis[nx][ny] == false)
		{
			
			dfs(nx,ny);
		}
	}
}

int main ()
{
	cin >> t;
	getline(cin,str);
	getline(cin,str);
	for(int k = 0 ; k < t ; k++)
	{
		
		getline(cin,str);
		sx = (str[0] - '0') * 10 + str[1] - '0';
		sy = (str[3] - '0') * 10 + str[4] - '0';
		m = 0;
		cnt = 0;
		memset(vis,false,sizeof(vis));
		while(getline(cin,str)&& str != "")
		{
			n = str.length();
			for(int i = 0 ; i < str.length() ; i++)
			{
				adj[m][i] = str[i] - '0';
			}	
			m++;
		}	
		dfs(sx-1,sy-1);
		
		cout << cnt << "\n";
		if(k != t-1)
			cout << "\n";
	}
} 
