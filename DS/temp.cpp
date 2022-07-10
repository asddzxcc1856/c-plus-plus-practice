#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

long long int f[850][300] = {}; // factorial table

int main ()
{
	f[0][0] = 0;
	f[1][0] = 0;
	f[2][0] = 1;
	f[3][0] = 2;
	for(int i = 4 ; i < 801 ; i++)
	{
		for(int j = 0 ; j < 300 ; j++)
		{
			f[i][j] += (i - 1) * (f[i - 1][j] + f[i - 2][j]);
			if(f[i][j] >= 100000000)
			{
				f[i][j + 1] += (f[i][j]/100000000);
				f[i][j] %= 100000000;
			}
		}
	}
	int n;
	while(cin >> n)
	{
		if(n == -1)
		{
			return 0;
		}
		int w;
		for(w = 299; w >= 0 && f[n][w] == 0 ; w--);
		cout << f[n][w];
		w--;
		for(; w >= 0 ; w--)
		{
			cout << setw(8) << setfill('0') << f[n][w];
		}
		cout << "\n";
	}
	
	
}
