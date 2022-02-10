#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	int t;
	cin >> t; 
	for (int k = 0 ; k < t ; k++)
	{
		int a,b;
		cin >> a >> b;
		
		int diff = abs(a - b);
		int ans = diff/10 + (diff%10 > 0 ? 1 : 0);
		
		
		cout << ans << "\n";
	}
}
