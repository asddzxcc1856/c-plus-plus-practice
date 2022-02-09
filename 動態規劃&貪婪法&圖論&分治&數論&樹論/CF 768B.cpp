#include <iostream>
#include <cmath>
using namespace std;

long long int n,l,r;
long long int ans;

void cnt(long long int now,long long int L,long long int R)
{
	if(L > R || R < l || L > r)
		return;
		
	long long int mid = (L + R) >>1;
	if(now % 2 == 1 && mid >= l && mid <= r)
	{
		ans++;
	}
	if(now != 0 && now != 1)
	{
		cnt(now/2,L,mid - 1);
		cnt(now/2,mid + 1,R);
	}
}

int main ()
{
	cin >> n >> l >> r;
	long long int L = 0,R = 0,exp = 0,t = n;
	while(t!=0)
	{
		R += pow(2LL,exp);
		exp++;
		t /= 2;
	}
	ans = 0;

	cnt(n,1,R);	
	
	cout << ans << "\n";
}
