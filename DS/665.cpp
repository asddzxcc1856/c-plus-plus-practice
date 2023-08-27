#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int w[105];
vector<int> v1[105],v2[105];
string vs[105];
int t,n,k;

int main ()
{
	cin >> t;
	for(int b = 1 ; b <= t ; b++)
	{
		cin >> n >> k;
		for(int i = 0 ; i < 105 ; i++)
		{
			v1[i].clear();
			v2[i].clear();
		}
		for(int i = 0 ; i < k ; i++)
		{
			int num;
			cin >> num;
			for(int j = 0 ; j < num ; j++)
			{
				int a;
				cin >> a;
				v1[i].push_back(a);
			}
			for(int j = 0 ; j < num ; j++)
			{
				int a;
				cin >> a;
				v2[i].push_back(a);
			}
			cin >> vs[i];
		}
		int ans = 0;
		int f = 0;
		for(int g = 0 ; g < 2; g++)
		{
			for(int q = 1 ; q <= n; q++)
			{
				memset(w,0,sizeof(w));
				w[q] = (g == 0 ? -1 : 1);
				int cnt = 0;
				for(int i = 0 ; i < k ; i++)
				{
					int s1 = 0,s2 = 0;
					for(int j = 0 ; j < v1[i].size() ; j++)
					{
						s1 += w[v1[i][j]];
					}
					for(int j = 0 ; j < v2[i].size() ; j++)
					{
						s2 += w[v2[i][j]];
					}
					string tmp;
					if(s1 == s2)
						tmp = "=";
					else if(s1 > s2)
						tmp = ">";
					else if (s1 < s2)
						tmp = "<";
					if(tmp == vs[i])
						cnt++;
				}
				if(cnt == k)
				{
					
					if(ans != q)
						f++;
					ans = q;
				}
			}
		}
		if(f >= 2 || f == 0)
			cout << 0 << "\n";
		else
			cout << ans << "\n";
		if(b != t)
			cout << "\n";
	}
}