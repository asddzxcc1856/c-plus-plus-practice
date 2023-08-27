#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int t;
	while(cin >> t)
	{
		for(int k = 1 ; k <= t ; k++)
		{
			int n;
			cin >> n;
			double all = 0;
			double c[1005];
			for(int i = 0 ; i < n ; i++)
			{
				cin >> c[i];
				all += c[i];
			}
			all /= n;
			double ans = 0;
			for(int i = 0 ; i < n ; i++)
			{
				if(c[i] > all)
					ans++;
			}
			cout << fixed << setprecision(3) << ans/n * 100 << "%\n";
		}
	}
}