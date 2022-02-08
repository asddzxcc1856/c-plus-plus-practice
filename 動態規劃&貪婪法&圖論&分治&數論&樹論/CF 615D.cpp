#include <iostream>
#include <map>
#define mod 1000000007
using namespace std;

unsigned long long int quickpow(unsigned long long int n,unsigned long long int m)
{
	unsigned long long int ans = 1;
	while(m > 0)
	{
		if(m&1)ans = ans * n%mod;
		m>>=1;
		n = n * n % mod;
	}
	return ans;
}

int main ()
{
	ios::sync_with_stdio(false),cin.tie(0);
	unsigned long long int m,n;
	map<unsigned long long int,unsigned long long int> ma;
	cin >> m;
	
	for(unsigned long long int k = 0 ; k < m ; k++)
	{
		cin >> n;
		ma[n]++;
	}	
	unsigned long long int d = 1,ans = 1,fp;

	for(map<unsigned long long int,unsigned long long int>::iterator it = ma.begin() ; it != ma.end() ; it++)
	{
		fp = quickpow(it->first,(it->second + 1 ) * it->second / 2);// f(p^k) = p ^ ((k + 1) * k / 2) 
		ans = quickpow(ans, (it->second + 1))*quickpow(fp,d)%mod; // ans^(k+1) * f(p^k)^d % mod; 
		d = d * (it->second + 1) % (mod - 1);// d * (k + 1) % (mod-1)
	}
	

	cout << ans << "\n";
	
	return 0;
} 
