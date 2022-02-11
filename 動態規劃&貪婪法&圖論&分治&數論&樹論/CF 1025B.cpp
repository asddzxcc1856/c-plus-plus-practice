#include <iostream>
#include <algorithm>
using namespace std;

long long int n;
long long int a[150005],b[150005];

int main()
{
	cin >> n;
	cin >> a[0] >> b[0];
	long long int gcd = a[0] * b[0] / __gcd(a[0],b[0]);  
	for(int k = 1 ; k < n ; k++)
	{
		cin >> a[k] >> b[k];
		gcd = __gcd(gcd,a[k]*b[k]/__gcd(a[k],b[k]));
	}
	if( gcd == 1)
	{
		cout << "-1\n";
	}
	else
	{
		long long int temp;
		for(int k = 0 ; k < n ; k++)
		{
			temp = __gcd(a[k],gcd);
			if(temp > 1)
			{
				gcd = temp;
				continue;
			}
			temp = __gcd(b[k],gcd);
			if(temp > 1)
			{
				gcd = temp;
			}
		}
		cout << gcd << "\n";
	}
	

	return 0;
}