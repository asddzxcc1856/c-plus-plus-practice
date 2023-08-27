#include <iostream>
#include <algorithm>
using namespace std;

int c[200005],b[200005];

int main ()
{
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		int n;
		cin >> n;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> c[i];
		}
		int q;
		cin >> q;
		for(int f = 0 ; f < q ; f++)
		{
			int l,r,len = 0;
			cin >> l >> r;
			if(r - l + 1 > 10000)
			{
				cout << "0\n";
				continue;
			}
			for(int j = l ; j <= r ; j++)
				b[len++] = c[j];
			sort(b,b+len);
			int minn = 2147483647;
			for(int j = 0 ; j < len - 1 ; j++)
			{
				minn = min(minn,b[j + 1] - b[j]);
			}
			cout << minn << "\n";
		}
	}
}