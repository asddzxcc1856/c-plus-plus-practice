#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct point{
	double x;
	double y;
	point() : x(0), y(0) {}
	double operator-(point b)
	{
		return sqrt((b.x - this->x)*(b.x - this->x) + (b.y - this->y)*(b.y - this->y));
	}
};

int main()
{
	int n,times = 1;
	while(cin >> n,n)
	{
		point p[205];
		for(int i = 0 ; i < n ; i++)
		{
			cin >> p[i].x >> p[i].y;
		}
		double dp[205][205];
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				dp[i][j] = 1000000000;
			}
		}
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = i + 1 ; j < n ; j++)
			{
				double w = p[i] - p[j];
				dp[i][j] = dp[j][i] = w;
			}
		}
		for(int k = 0 ; k < n ; k++)
		{
			for(int i = 0 ; i < n ; i++)
			{
				for(int j = 0 ; j < n ; j++)
				{
					if(dp[i][k] != 1000000000 && dp[k][j] != 1000000000)
					{
						dp[i][j] = min(dp[i][j],max(dp[i][k],dp[k][j]));
					}
				}
			}
		}
		
		cout << "Scenario #" << times++ << "\n";
		cout << "Frog Distance = "<< fixed << setprecision(3) << dp[0][1] << "\n\n";
		
	}
}