#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isp(int n)
{
	if(n == 2)
		return true;
	else
	{
		for(int i = 2 ; i * i <= n ; i++)
		{
			if(n % i == 0)
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
	
	for(int i = 2 ; i <= 32767 ; i++)
	{
		if(isp(i))
			p.push_back(i);
	}
	map<int,int> ma;
	for(int i = 0 ; i < p.size() ; i++)
	{
		for (int j = i ; j < p.size() ; j++)
		{
			ma[p[i] + p[j]]++;
		}
	}
	
	int n;
	while(cin >> n,n)
	{
		cout << ma[n] << "\n";
	}
	
}
