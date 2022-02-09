#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct interval{
	int left;
	int right;
};
int n;
int a,b,c;
bool vis[105];
vector<int> v[105];
interval t[105];
bool ok;

bool check(int a,int b)
{
	return (t[b].left < t[a].left && t[a].left < t[b].right)||(t[b].left < t[a].right && t[a].right < t[b].right);
}

void dfs(int now)
{
	if(now == c)
	{
		ok = true;
		return;
	}
	
	for(int i = 0 ; i < n ; i++)
	{
		if(vis[i] == false)
		{
			if(check(now,i))
			{
				vis[i] = true;
				dfs(i);
			}
			
		}
	}
	
}

int main ()
{
	int q;
	n = 1;
	cin >> q;
	for(int k = 1 ; k <= q ; k++)
	{
		
		cin >> a >> b >> c;
		if(a == 1)
		{
			t[n].left = b;
			t[n].right = c;
			n++;
		}
		else if (a == 2)
		{
			ok = false;
			memset(vis,false,sizeof(vis));
			vis[b] = true;
			dfs(b);
			if(ok)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		} 
	}
}
