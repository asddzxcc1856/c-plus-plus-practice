#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main ()
{
	int t,n;
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		cin >> n;
		vector<int> va,vb;
		for(int i = 0 ; i < n ; i++)
		{
			int a;
			cin >> a;
			va.push_back(a);
		}
		for(int i = 0 ; i < n ; i++)
		{
			int b;
			cin >> b;
			vb.push_back(b);
		}
		sort(va.begin(),va.end());
		sort(vb.begin(),vb.end());
		bool ok = true;
		for(int i = 0 ; i < n ; i++)
		{
			if(vb.at(i) - va.at(i) > 1 || vb.at(i) - va.at(i) <= -1)
			{
				ok = false;
			}
		}
		if(ok)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}