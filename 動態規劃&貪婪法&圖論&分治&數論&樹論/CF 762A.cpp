#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<long long int> se; 

int main ()
{
	long long int n,k;
	cin >> n >> k;
	se.insert(1);
	se.insert(n);
	for(long long int i = 2 ; i * i <= n ; i++)
	{
		if(n % i == 0)
		{
			se.insert(i);
			se.insert(n/i);
		}
	}
	
	if(se.size() >= k)
	{
		int i = 1;
		for(set<long long int>::iterator it = se.begin() ; it != se.end() ; it++ , i++)
		{
			if(i == k)
			{
				cout << *it << "\n"; 
				break;
			}
		}
	}
	else
		cout << "-1\n";
}
