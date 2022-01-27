#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector> 
#include <cmath>
using namespace std;

vector<int> p;
char dp[1000001];
bool isp(int n)
{
	if( n == 2 )
		return true;
	else
	{
		for(int i = 2 ; i * i <= n ; i++)
		{
			if(n % i == 0)
				return false;
		}
	}
	return true;
}

int main ()
{
	memset(dp,0,sizeof(dp));
	for(int i = 100 ; i <= 1000000 ; i++)
	{
		int temp = i;
		int cnt = 1;
		int y;
		for(y = 10; y <= temp ; y *= 10)
		{
			cnt++;
		}
		int cnt2 = 0;
		int temp2;
		for(int j = 0 ; j < cnt ; j++)
		{
			temp2 = temp;
			if(isp(temp2))
			{
				cnt2++;
			}
			else
			{
				break;
			}
			temp = (temp % (int)pow(10,(cnt - 1))) * 10 + (temp / (int)pow(10,(cnt - 1)));
		}
		if(cnt2 == cnt)
			dp[i] = dp[i - 1] + 1;
		else
			dp[i] = dp[i - 1];
	}
	int a,b;
	while(cin >> a && a != -1)
	{
		cin >> b;
		int ans = dp[b] - dp[a - 1];
		if(ans)
		{
			if(ans == 1)
				cout << ans << " Circular Prime.\n"; 
			else
				cout << ans << " Circular Primes.\n";
		}
		else
		{
			cout << "No Circular Primes.\n";
		}
	}
}
