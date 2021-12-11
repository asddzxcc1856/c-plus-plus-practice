#include <iostream>
using namespace std;

int t,n,c[55],i,j,k,cnt;

int main ()
{
	cin >> t;
	for (k = 0 ; k < t ; k++)
	{
		cin >> n;
		for (i = 0 ; i < n ; i++)
		{
			cin >> c[i]; 
		}
		cnt = 0;
		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 1 ; j < n - i ; j++)
			{
				if(c[j] < c[j - 1])
				{
					int temp = c[j];
					c[j] = c[j - 1];
					c[j - 1] = temp;
					cnt++;
				}
			}
		}
		cout << "Optimal train swapping takes " << cnt << " swaps.\n";
	}
    return 0;
}

