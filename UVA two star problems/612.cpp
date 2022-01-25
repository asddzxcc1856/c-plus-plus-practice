#include <iostream>
#include <algorithm>
using namespace std;

struct s{
	int num;
	int pos;
};

bool cmp(s a,s b)
{
	if(a.num != b.num)
		return a.num < b.num;
	else
		return a.pos < b.pos;
}

int t,m,n;
char adj[105][55];
s pre[105];

int main ()
{	
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		cin >> n >> m;
		for(int i = 0 ; i < m ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				cin >> adj[i][j];
			}
		}
		for(int i = 0 ; i < m ; i++)
		{
			pre[i].num = 0;
			pre[i].pos = i;	
		}
		for(int i = 0 ; i < m ; i++)
		{
			int sum = 0;
			for (int j = 0 ; j < n ; j++)
			{
				for(int w = j + 1 ; w < n ; w++)
				{
					if(adj[i][j] > adj[i][w])
					{
						sum+=1;			
					}
				}
			}
			pre[i].num = sum;
		}
		sort(pre,pre+m,cmp);
		for(int i = 0 ; i < m ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				cout << adj[pre[i].pos][j];	
			}	
			cout << "\n";
		}
		if(k != t - 1)
			cout << "\n";
	}
	
	return 0;
} 
