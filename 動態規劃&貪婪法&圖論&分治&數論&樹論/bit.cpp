#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 100005;
ll bit[maxn];

void modify(ll i,ll val)
{
	while(i <= maxn) bit[i] += val , i += i & -i;
}

ll query(ll i)
{
	ll ret = 0;
	while(i > 0) ret += bit[i], i -= i & -i;
	return ret; 
}

int main ()
{
	ll a[6] = {0,1,3,5,7,9};
	memset(bit,0,sizeof(bit));
	for(int i = 1 ; i <= 5 ; i++)
	{
		modify(i,a[i]);
	}
	modify(3,20);
	for(int i = 1 ; i <= 5 ; i++)
	{
		cout << query(i) - query(i - 1) << "\n";
	}
}