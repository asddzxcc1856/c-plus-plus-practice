#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p;

bool isp(int n)
{
	if(n == 2)
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
	for(int i = 2 ; i <= 1299709 ; i++)
	{
		if(isp(i))
			p.push_back(i);
	}
	
	int n;
	while(cin >> n,n)
	{
		if(isp(n))
		{
			cout << "0\n"; 
		}
		else
		{
			vector<int>::iterator it = upper_bound(p.begin(),p.end(),n);
			vector<int>::iterator it2 = it;
			it2--;
			cout << *it - *it2 << "\n";
		}
	}
}
