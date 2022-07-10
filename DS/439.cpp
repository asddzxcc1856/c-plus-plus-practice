#include <iostream>
#include <cstring>
#include <queue>
#define clr(n,k) memset(n,k,sizeof(n))
using namespace std;


int mx[8] = {-1,-2,-1,-2,1,2,1,2};
int my[8] = {-2,-1,2,1,-2,-1,2,1};
bool vis[8][8];
int sx,sy,ex,ey,ans;


void bfs()
{		
	if(sx == ex && sy == ey)
	{
		ans = 0;
		return;
	}
	vis[sx][sy] = true;
	queue<int> qx,qy,qd;
	qx.push(sx);
	qy.push(sy);
	qd.push(0);
	while(!qx.empty())
	{
		if(ans != -1)
			return;
		int x = qx.front();
		qx.pop();
		int y = qy.front();
		qy.pop();
		int d = qd.front();
		qd.pop();
		for(int i = 0 ; i < 8 ; i++)
		{
			int nx = x + mx[i],ny = y + my[i];
			if((nx >= 0 && nx < 8) && (ny >= 0 && ny < 8))
			{
				if(vis[nx][ny] == false)
				{
					vis[nx][ny] = true;
					if(nx == ex && ny == ey)
					{
						ans = d + 1;
						return;
					}
					else
					{
						qx.push(nx);
						qy.push(ny);
						qd.push(d + 1);
					}	
				}
				
			}
		}	
	}
}

int main()
{
	string m,n;
	while(cin >> m >> n)
	{
		sx = m[1] - '1';
		sy = m[0] - 'a';
		ex = n[1] - '1';
		ey = n[0] - 'a';
		ans = -1;
		clr(vis,false);
		bfs();
		cout << "To get from " << m << " to " << n << " takes " << ans << " knight moves.\n";
	}
}