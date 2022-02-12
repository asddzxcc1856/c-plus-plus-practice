#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main ()
{
	int t;
	cin >> t;
	for(int i = 0 ; i < t ; i++)
	{
		ll a,b;
		cin >> a >> b;
		if(a == b)
		{
			cout << "0 0\n";
		}
		else if (abs(a - b) == 1)
		{
			cout << abs(a - b) << " " << 0 << "\n";
		}
		else if(a == 0 || b ==0)
		{
			cout << abs(a - b) << " " << 0 << "\n";
		}
		else
		{
			ll diff = abs(a - b);
			ll maxn = max(a,b);
			cout << diff << " " << min(maxn % diff,diff - maxn % diff) << "\n"; 
		}
	}
}