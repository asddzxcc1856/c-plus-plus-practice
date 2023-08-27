#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1000001]; 

int main()
{
	int m,n;
	while(cin >> n >> m)
	{
		for(int i = 1 ; i <= 1000000 ; i++)
			v[i].clear();
			
		int tmp;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> tmp;
			v[tmp].push_back(i);
		}	
		
		int k,val;
		for(int i = 0 ; i < m ; i++)
		{
			cin >> k >> val;
			if(v[val].size() >= k)
			{
				cout << v[val][k - 1] << "\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		
	}	
} 
