#include <iostream>
using namespace std;

int main ()
{
	int t;
	int c[105],d[105];
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		int r,b;
		cin >> r;
		for(int i = 0 ; i < r ; i++)
			cin >> c[i];
		cin >> b;
		for(int i = 0 ; i < b ; i++)
			cin >> d[i];
			
		int sum1,sum2,ans1 = 0,ans2 = 0;
		sum1 = c[0];
		sum2 = d[0];
		for(int i = 1 ; i < r ; i++)
		{
			ans1 = max(ans1,sum1);
			sum1 = sum1 + c[i];
		}
		for(int i = 1 ; i < b ; i++)
		{
			ans2 = max(ans2,sum2);
			sum2 = sum2 + d[i];
		}
		ans1 = max(ans1,sum1);
		ans2 = max(ans2,sum2);
		cout << ans1 + ans2 << "\n";
	}
}
