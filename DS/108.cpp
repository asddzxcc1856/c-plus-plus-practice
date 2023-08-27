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
			s += a[i];
		else
			s = a[i];
		sum = max(sum,s);
	}
	return sum;
}

int max2D(int a[][105],int n)
{
	int sum = -1e9;
	int s[105];
	for(int i = 0 ; i < n ; i++)
	{
		memset(s,0,sizeof(s));
		for(int j = i ; j < n ; j++)
		{
			for(int k = 0; k < n ; k++)
			{
				s[k] += a[j][k];
			}
			sum = max(sum,max1D(s,n));
		}
	}
	return sum;
}

int main ()
{
	int n;
	int a[105][105];
	while(cin >> n)
	{
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				cin >> a[i][j];	
			}	
		}
		int ans = max2D(a,n);
		cout << ans << "\n";
	}
	
}