#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

int x,n;
vector<int> v;
string str;

signed main ()
{

	while(cin >> x)
	{
		
		getline(cin,str);
		getline(cin,str);
		stringstream ss(str);
		v.clear();
		while(ss >> n)
		{
			v.push_back(n);
		}
		v.pop_back();
		reverse(v.begin(),v.end());
		int ans = 0;
		long long int mul = 1;
		for(int i = 0 ; i < v.size() ; i++)
		{
			ans += v[i] * (i + 1) * mul;
			mul *= x;
		}
		cout << ans << "\n"; 
	}

    return 0;
}

