#include <iostream>
#include <cmath>
#define int long long
using namespace std;


signed main ()
{
	int t;
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		int l,r,m,n;
		cin >> l >> r >> m;
		int left =  m + l - r;
		int right = m + r - l;
		int a;
		for(a = l ; a <= r ; a++)
		{
			n = floor(right / a);
			if(left <= n*a && n*a <= right)
			{
				break;
			}
		}
		// m = n * a + b - c
		// n * a = m + c - b
		// c - b = n*a - m
		// c = b + n*a - m
		// b = c - n*a + m
		if(n * a - m < 0)
		{
			cout << a << " " << r << " " << r + n*a - m << "\n";
		}
		else
		{
			cout << a << " " << r - n*a + m << " " << r << "\n";
		}
	}	
} 
