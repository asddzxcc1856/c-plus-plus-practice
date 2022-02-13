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
	ll sum = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int a;
		cin >> a;
		sum += a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	ll temp = 0,ans = 0;
	for(int i = 0 ; i < v.size() ; i++)
	{
		ans += sum + temp;
		temp = v[i];
		sum -= v[i];
	} 
	cout << ans << "\n";
}