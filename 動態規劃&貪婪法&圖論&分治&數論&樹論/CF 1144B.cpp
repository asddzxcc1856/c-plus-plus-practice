#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> odd,even;

int main ()
{
	int n,m;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int a;
		cin >> a;
		if(a & 1)
		{
			odd.push_back(a);
		}
		else
		{
			even.push_back(a);
		}
	}
	
	sort(even.begin(),even.end());
	sort(odd.begin(),odd.end());
	if(odd.size() >= even.size())
	{
		bool o = true;
		int ans = 0;
		for(int i = 0 ; i < n ; i++)
		{
			if(o)
			{
				if(odd.size() > 0)
					odd.pop_back();
				else
					break;
				o = false;
			}	
			else
			{
				if(even.size() > 0)
					even.pop_back();
				else
					break;
				o = true;
			}
		}
		while(odd.size() > 0)
		{
			ans += odd.back();
			odd.pop_back();
		}
		while(even.size() > 0)
		{
			ans += even.back();
			even.pop_back();
		}
		cout << ans << "\n";
	}
	else
	{
		bool o = false;
		int ans = 0;
		for(int i = 0 ; i < n ; i++)
		{
			if(o)
			{
				if(odd.size() > 0)
					odd.pop_back();
				else
					break;
				o = false;
			}	
			else
			{
				if(even.size() > 0)
					even.pop_back();
				else
					break;
				o = true;
			}
		}
		while(odd.size() > 0)
		{
			ans += odd.back();
			odd.pop_back();
		}
		while(even.size() > 0)
		{
			ans += even.back();
			even.pop_back();
		}
		cout << ans << "\n";
	}
}