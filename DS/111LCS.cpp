#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int m[5005];
int n[5005];
int b[5005];
vector<int> v[5005];
int main ()
{
	int num;
	cin >> num;
	
	for(int i = 1 ; i <= num ; i++)
	{
		cin >> m[i];
	}
	int c;
	while(cin >> c)
	{
		n[c] = m[1];
		for(int i = 2 ; i <= num ; i++)
		{
			cin >> c;
			n[c] = m[i];
		}
		for(int i = 1 ; i <= num ; i++)
		{
			b[i] = n[i];
		}
		sort(b+1,b+num + 1);
		for(int i = 1 ; i <= num ; i++)
		{
			v[i].clear();
		}
		for(int i = 1 ; i <= num ; i++)
		{
			v[b[i]].push_back(i);
		}
		vector<int> lis;
		lis.push_back(0);
		for(int i = 1 ; i <= num ; i++)
		{
			for(int j = 0 ; j < v[n[i]].size() ; j++)
			{
				if(lis.back() < v[n[i]][j])
				{
					lis.push_back(v[n[i]][j]);
				}
				else
				{
					*lower_bound(lis.begin(),lis.end(),v[n[i]][j]) = v[n[i]][j];
				}
			}
		}
		cout << lis.size() - 1 << "\n";
	}
	return 0;
}