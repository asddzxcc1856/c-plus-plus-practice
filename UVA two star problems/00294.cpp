#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isp(int n)
{
	if(n == 2)
		return true;
	else
	{
		for (int i = 2 ; i*i <= n ; i++ )
		{
			if(n%i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main ()
{
	vector<int> p;
	for(int i = 2 ; i <= 32000 ; i++)
	{
		if(isp(i))
			p.push_back(i);
	}
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++)
	{
		int a,b,ans,maxn = 0;
		cin >> a >> b;
		for(int j = a ; j <= b ; j++)
		{
			int t = j;
			int num = 1;
			for(int x = 0 ; x < p.size() ; x++)
			{
				int cnt = 0;
				while(t % p[x] == 0)
				{
					cnt++;
					t /= p[x];
				}
				num *= (cnt + 1);
			}
			if(num > maxn)
			{
				maxn = num;
				ans = j;
			}
		}	
		cout << "Between " << a <<" and " << b << ", " << ans << " has a maximum of " << maxn << " divisors.\n";
	}	
} 
