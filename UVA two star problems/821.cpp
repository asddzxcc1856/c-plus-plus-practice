#include <iostream>
#include <iomanip>
#include <cstring>
#define INF 2147483647
using namespace std;

int adj[105][105];

void floyd_wars()
{
	
	for(int k = 0 ; k < 105 ; k++)
	{
		for(int i = 0 ; i < 105 ; i++)
		{
			for(int j = 0 ; j < 105 ; j++)
			{
				if(i!=j && adj[i][k] != INF && adj[k][j] != INF)
					adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
			}
		}
	}
}

int main ()
{
	for(int i = 0 ; i < 105 ; i++)
	{
		for(int j = 0 ; j < 105 ; j++)
		{
			adj[i][j] = INF;
		}
	}
	int stop = 0,a,b,num = 0,times = 1;
	while(cin >> a >> b)
	{
		
		if( a == 0 && b == 0 )
		{
			if(stop == 1)
			{
				return 0;
			}
			else
			{
				floyd_wars();
				double sum = 0;
				for(int i = 0 ; i < 105 ; i++)
				{
					for(int j = 0 ; j < 105 ; j++)
					{
						if(i!=j&&adj[i][j] != INF)
						{
							sum += adj[i][j];
							num++;
						}
					}
				}
				cout << "Case " << times++ << ": average length between pages = " << fixed << setprecision(3) << sum/num << " clicks\n";
				stop = 1;
				num = 0;
				for(int i = 0 ; i < 105 ; i++)
				{
					for(int j = 0 ; j < 105 ; j++)
					{
						adj[i][j] = INF;
					}
				}
			}
			
		}
		else
		{
			stop = 0;
			adj[a][b] = 1;
		}
		
			
	}
}
