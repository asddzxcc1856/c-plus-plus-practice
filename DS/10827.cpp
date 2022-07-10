#include <iostream>
#include <cstring>
using namespace std;

int max1D(int a[],int n)
{
	int sum = -1e9;
	int s = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if(s >= 0)
		{
			s += a[i];
		}
		else
		{
			s = a[i];
		}
			
		sum = max(sum,s);
	}
	return sum;
}

int max2D(int a[][400],int n)
{
	int sum = -1e9;
	int s[400];
	for(int q = 0 ; q < n ; q++)
	{
		for(int w = 0 ; w < n ; w++)
		{
			memset(s,0,sizeof(s));
			for(int j = q ; j < n + q ; j++)
			{
				int tmp = 0;
				for(int k = w ; k < n + w ; k++)
				{
					s[k] += a[j][k];
					tmp += s[k];
					sum = max(sum,tmp);
				}
			}
			
		}
	}
		
	return sum;
}


int main ()
{
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		int n;
		cin >> n;
		int a[400][400];
		memset(a,0,sizeof(a));
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				cin >> a[i][j];
				a[n + i][j] = a[i][n + j] = a[n + i][n + j] = a[i][j];
			}
		}
		int ans = max2D(a,n);
		cout << ans << "\n";
	}
}