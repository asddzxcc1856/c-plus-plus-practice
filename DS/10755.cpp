#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int a,b,c;

int max1D(int a[])
{
	int sum = -1e12;
	int s = 0;
	for(int i = 0 ; i < c ; i++)
	{
		if(s >= 0)
			s += a[i];
		else
			s = a[i];
		sum = max(sum,s);
	}
	
	return sum;
}

int max2D(int a[][25])
{
	int sum = -1e12;
	int s[25];
	for(int i = 0 ; i < b ; i++)
	{
		memset(s,0,sizeof(s));
		for(int j = i ; j < b ; j++)
		{
			for(int k = 0 ; k < c ; k++)
			{
				s[k] += a[j][k];
			}
			sum = max(sum,max1D(s));
		}
	}
	return sum;
}

int max3D(int ar[][25][25])
{
	int sum = -1e12;
	int s[25][25];
	for(int i = 0 ; i < a ; i++)
	{
		memset(s,0,sizeof(s));
		for(int j = i ; j < a ; j++)
		{
			for(int w = 0 ; w < b ; w++)
			{
				for(int q = 0 ; q < c ; q++)
				{
					s[w][q] += ar[j][w][q];
				}
			}
			sum = max(sum,max2D(s));
		}
	}
	return sum;
}

signed main ()
{
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		if(k != 1)
			cout << "\n";
		cin >> a >> b >> c;
		int ar[25][25][25];
		for(int i = 0 ; i < a ; i++)
		{
			for(int j = 0 ; j < b ; j++)
			{
				for(int k = 0 ; k < c ; k++)
				{
					cin >> ar[i][j][k]; 
				}
			}
		}
		int ans = max3D(ar);
		cout << ans << "\n";
	}
}