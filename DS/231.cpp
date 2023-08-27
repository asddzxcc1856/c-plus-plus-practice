#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> c;
vector<int> v;
vector<int> dp,dp2;

int main ()
{
	int n,m,times = 1;
	while(cin >> n)
	{
		if(n == -1)
		{
			break;
		}
		if(times != 1)
			cout << "\n";
		v.clear();
		dp.clear();
		c.push_back(n);
		v.push_back(n);
		dp.push_back(1);
		while(cin >> m)
		{
			if(m == -1)
			{
				break;
			}
			c.push_back(m);
			if(v.back() < m)
			{
				v.push_back(m);
				dp.push_back(v.size());
			}
			else
			{
				vector<int>::iterator pos = lower_bound(v.begin(),v.end(),m);
				*pos = m;
				dp.push_back(pos - v.begin() + 1);
			}
		}
		v.clear();
		dp2.clear();
		v.push_back(c[c.size() - 1]);
		dp2.push_back(1);
		for(int i = c.size() - 2 ; i >= 0 ; i--)
		{
			if(v.back() < c[i])
			{
				v.push_back(c[i]);
				dp2.push_back(v.size());
			}
			else
			{
				vector<int>::iterator pos = lower_bound(v.begin(),v.end(),c[i]);
				*pos = c[i];
				dp2.push_back(pos - v.begin() + 1);
			}
		}
		int ans = 1;
		for(int i = 0 ; i < dp.size() ; i++)
		{
			ans = max({ans,dp[i],dp2[i]});
		} 
		cout << "Test #" << times++ << ":\n";
		cout << "  maximum possible interceptions: ";
		cout << ans << "\n";
	}
	return 0;
}