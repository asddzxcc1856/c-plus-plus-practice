#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1000001];

int main ()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	while(cin >> n >> m)
	{
		for(int i = 0 ; i < 1000001 ; i++)
			v[i].clear();
		for(int i = 1 ; i <= n ; i++)
		{
			int a;
			cin >> a;
			v[a].push_back(i);
		}
		for(int i = 0 ; i < m ; i++)
		{
			int k,num;
			cin >> k >> num;
			if(v[num].size() >= k)
			{
				cout << v[num][k - 1] << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
	}
}