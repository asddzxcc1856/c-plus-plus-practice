#include <iostream>
#include <iomanip>
using namespace std;

int d[1005],s[1005];

int main ()
{
	int n,t;
	while(cin >> n >> t)
	{
		double l = 2147483647,r;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> d[i] >> s[i];
			l = min(l,(double)s[i]);
		}
		l = -l,r = 2147483647;
		for(int i = 0 ; i < 80 ; i++)
		{
			double c = (l+r)/2, ti = 0;
			for(int i = 0 ; i < n && ti < t ; i++)
			{
				ti += d[i]/(s[i] + c);
			}
			if(ti > t)
			{
				l = c;
			}
			else
			{
				r = c;
			}
		} 
		cout << fixed << setprecision(9) << l << "\n";
	}
}
