#include <bits/stdc++.h>
using namespace std;

multiset<long long int> urn;

int main ()
{
	int N;
	while(cin >> N)
	{
		if(N == 0)
		{
			return 0;
		} 
		else
		{
			long long int cost = 0;
			for(int i = 0 ; i < N ; i++)
			{
				int k;
				cin >> k;
				for(int j = 0 ; j < k ; j++)
				{
					int bill;
					cin >> bill;
					urn.insert(bill);	
				}
				int hi = *urn.rbegin();
				urn.erase((++urn.rbegin()).base());
				int lo = *urn.begin();
				urn.erase(urn.begin());
				cost += hi - lo;
			}
			cout << cost << "\n";
			urn.clear();
		}
	}
}
