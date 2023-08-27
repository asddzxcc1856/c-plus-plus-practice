#include <iostream>
using namespace std;

int x[100000];

int main ()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int T,N,Q;
	cin >> T;
	for(int k = 0 ; k < T ; k++)
	{
		cin >> N >> Q;
		for(int i = 0 ; i < N ; i++)
		{
			cin >> x[i]; 
		}
		int ans[230];
		for(int i = 0 ; i < 230 ; i++)
		{
			ans[i] = 0;
			for(int j = 0 ; j < N ; j++)
			{
				ans[i] = max(ans[i],i & x[j]);
			}
		}
		for(int i = 0 ; i < Q ; i++)
		{
			int a;
			cin >> a;
			cout << ans[a] << "\n";
		}
	}
}
