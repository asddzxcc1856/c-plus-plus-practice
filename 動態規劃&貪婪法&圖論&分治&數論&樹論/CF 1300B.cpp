#include <iostream>
#include <algorithm>
using namespace std;

int c[200005];

int main ()
{
	int t;
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		int n,a,b,q;
		cin >> n;
		for(int i = 0 ; i < 2 * n ; i++)
		{
			cin >> c[i];
		}
		sort(c,c+2*n);
		cout << abs(c[n] - c[n - 1]) << "\n";
	}
}
