#include <iostream>
#include <vector>
using namespace std;

int pa[30000];
int size[30000];
vector<int> g[500];

int findpa(int n)
{
	return pa[n] == n ? n : findpa(pa[n]);
}

int main()
{
	int m,n,k,tmp;
	while(cin >> n >> m && !(n == 0 && m == 0))
	{
		for(int i = 0 ; i < m ; i++)
			g[i].clear();
		for(int i = 0 ; i < m ; i++)
		{
			cin >> k;
			for(int j = 0 ; j < k ; j++)
			{
				cin >> tmp;
				g[i].push_back(tmp);
			}
		}
		for(int i = 0 ; i < n ; i++)
		{
			pa[i] = i;
			size[i] = 1;
		}
		for(int i = 0 ; i < m ; i++)
		{
			
			for(int j = 1 ; j < g[i].size() ; j++)
			{
				int a = findpa(g[i][0]);
				int b = findpa(g[i][j]);
				if(a != b)
				{
					if(size[a] >= size[b])
					{
						pa[b] = pa[a];
						size[a] += size[b];
					}
					else
					{
						pa[a] = pa[b];
						size[b] += size[a];
					}
				}
			}
		}
		int a = findpa(0);
		cout << size[a] << "\n";
	}	
} 
