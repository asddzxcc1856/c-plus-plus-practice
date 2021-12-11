#include <iostream>
using namespace std;

int main ()
{
	int a,b,c1,c2,carry,ans;
	while(cin >> a >> b)
	{
		if(a == 0 && b == 0) 
			return 0;
		
		carry = 0;
		ans = 0;
		while(a!=0 || b!=0)
		{
			c1 = a%10;
			c2 = b%10;
			if(c1 + c2 + carry >= 10)
			{
				carry = 1;
				ans++;
			}
			else
			{
				carry = 0;
			}
			a/=10;
			b/=10;
		}
		if(ans > 1)
		{
			cout << ans << " carry operations.\n";
		}
		else if(ans == 1)
		{
			cout << ans << " carry operation.\n";
		}
		else
		{
			cout << "No carry operation.\n";
		}
	}	
	return 0;
} 
