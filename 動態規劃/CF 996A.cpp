#include <iostream>
using namespace std;

int main ()
{
	int c[5] = {1,5,10,20,100};
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 4 ; i >= 0 ; i--)
	{
		while(n >= c[i])
		{
			ans += n / c[i];
			n %= c[i];
		}
	}	
	
	cout << ans << "\n";
} 
