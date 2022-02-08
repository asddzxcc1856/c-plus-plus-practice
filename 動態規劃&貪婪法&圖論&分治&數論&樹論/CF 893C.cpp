#include <iostream> 
#define ll long long
using namespace std;

int num[100005],p[100005];
int n,m,a,b,rx,ry;

int findp(int now)
{
	if(p[now] == now)
		return now;
	
	int y = findp(p[now]);
	p[now] = y;
	return y;
}

int main ()
{
	ios::sync_with_stdio(false),cin.tie(0);
	
	ll ans = 0;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> num[i];
		p[i] = i;
	}	
	for(int i = 0 ; i < m ; i++)
	{
		cin >> a >> b;
		rx = findp(a);
		ry = findp(b);
		
		if(num[rx] < num[ry])
		{
			p[ry] = rx;
		}
		else
		{
			p[rx] = ry;
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(p[i] == i)
			ans += num[i];
	}
	cout << ans << "\n"; 
} 
