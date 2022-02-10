#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
	int t,n;
	int c[55];
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		cin >> n;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> c[i];
		}
		sort(c,c+n);
		for(int i = 0 ; i < n - 1 ; i++)
		{
			if(c[i + 1] - c[i] <= 1)
			{
				c[i] = 0;
			}
		}
		int cnt = 0;
		for(int i = 0 ; i < n ; i++)
		{
			if(c[i] != 0)
			{
				cnt++;
			}
		}
		if(cnt <= 1)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}
