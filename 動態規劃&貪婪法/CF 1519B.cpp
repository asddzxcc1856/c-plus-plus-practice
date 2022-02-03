#include <iostream>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		int n,m,c;
		cin >> n >> m >> c;
		int all = (n - 1) + (m - 1) * (n);
		if(all == c)
		{
			cout << "YES\n";
		} 	
		else
		{
			cout << "NO\n";
		}
	}	
} 
