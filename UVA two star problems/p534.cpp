#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct p{
	double x,y;
};

double adj[205][205];
p c[205];

int main ()
{
	int n;
	int times = 1;
	while(cin >> n)
	{
		if(n == 0)
			return 0;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> c[i].x >> c[i].y;
		}
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				adj[i][j] = sqrt((c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y));
			}
		}
		for(int k = 0 ; k < n ; k++)
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < n ; j++)
					adj[i][j] = min(adj[i][j],max(adj[i][k],adj[k][j]));
		cout << "Scenario #" << times++ << "\n";
		cout << "Frog Distance = " << fixed << setprecision(3) << adj[0][1] << "\n\n";
	}
}
