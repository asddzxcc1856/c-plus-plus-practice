#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c[10005];
int dp[10000],dp2[10000]; 

int main ()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int n;
	while(cin >> n)
	{
		for(int i = 0 ; i < n ; i++)
			cin >> c[i];
		vector<int> vl,vr;
		vl.push_back(c[0]);
		vr.push_back(c[n - 1]);
		dp2[n - 1] = 1;
		dp[0] = 1;
		for(int i = 1 ; i < n ; i++)
		{
			if(vl.back() < c[i])
			{
				vl.push_back(c[i]);
				dp[i] = vl.size();
			}
			else
			{
				vector<int>::iterator pos = lower_bound(vl.begin(),vl.end(),c[i]);
				*pos = c[i];
				dp[i] = pos - vl.begin() + 1;
			}
		}

		for(int i = n - 2 ; i >= 0 ; i--)
		{
			if(vr.back() < c[i])
			{
				vr.push_back(c[i]);
				dp2[i] = vr.size();
			}
			else
			{
				vector<int>::iterator pos = lower_bound(vr.begin(),vr.end(),c[i]);
				*pos = c[i];
				dp2[i] = pos - vr.begin() + 1;
			}
		}
		int l = 1;
		for(int i = 0 ; i < n ; i++)
		{
			l = max(l,min(dp[i],dp2[i]));
		}
		cout << l * 2  - 1 << "\n";
	}
}