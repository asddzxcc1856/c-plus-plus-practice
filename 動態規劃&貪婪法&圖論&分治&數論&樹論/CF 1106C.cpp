#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> v;

int main ()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	ll ans = 0;
	for(int i = 0 ; i < n/2 ; i++)
	{
		ans += pow((v[i] + v[n - i - 1]),2LL);
	}
	cout << ans << "\n";
}