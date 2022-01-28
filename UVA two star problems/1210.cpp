#include <iostream>
#include <vector>
using namespace std;

vector<int> p;

bool isp(int n)
{
	if(n == 2)
		return true;
	else
	{
		for (int i = 2 ; i * i <= n ; i++)
		{
			if(n % i == 0)
				return false;
		}
	}
	return true;
}

int main ()
{
	for(int i = 2 ; i <= 10000 ; i++)
	{
		if(isp(i))
		{
			p.push_back(i);
		}
	}
	int n;
	while(cin >> n,n)
	{
		int ans = 0;
		for(int i = 0 ; i < p.size() ; i++)
		{
			int sum = 0;
			for (int j = i  ; j < p.size() && sum <= n ; j++)
			{
				if(sum == n)
					ans++;
				sum += p[j];
			}
		}
		cout << ans << "\n";
	}
}
