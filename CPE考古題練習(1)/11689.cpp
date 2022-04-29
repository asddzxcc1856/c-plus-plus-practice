#include <iostream>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int now = a + b,ans = 0;
		while(c <= now)
		{
			int temp = now / c;
			now %= c;
			now += temp;
			ans += temp;
		}	
		cout << ans << "\n";
	} 
}