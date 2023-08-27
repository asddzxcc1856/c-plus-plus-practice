#include <iostream>
#include <vector> 
using namespace std;

vector<int> ma[10001];
vector<int> loc[10001];
vector<int> tmp(10001);

int main()
{
	int m,n;
	while(cin >> m >> n)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			ma[i].clear();
			loc[i].clear();
		}
		for(int i = 1 ; i <= m ; i++)
		{
			int k;
			cin >> k;
			for(int j = 0 ; j < k ; j++)
			{
				cin >> tmp[j];
			}
			for(int j = 0 ; j < k ; j++)
			{
				int num;
				cin >> num;
				ma[tmp[j]].push_back(num);
				loc[tmp[j]].push_back(i);
			}
			tmp.clear();
		}
		cout << n << " " << m << "\n";
		for(int i = 1 ; i <= n ; i++)
		{
			int k = loc[i].size();
			cout << k;
			for(int j = 0 ; j < k ; j++)
			{
				cout << " " << loc[i][j];
			}
			cout << "\n";
			for(int j = 0 ; j < k - 1 ; j++)
			{
				cout << ma[i][j] << " ";
			}
			if(k > 0)
			{
				cout << ma[i][k - 1] << "\n";		
			} 
			else
			{
				cout << "\n";
			}
		}
	}
}
