#include <iostream>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	for(int i = 0 ; i < t ; i++)
	{
		int n;
		cin >> n;
		if(n == 1)
		{
			cout << "-1\n";
		}
		else
		{
			int now = 3;
			string ans = "3";
			for(int k = 1 ; k < n ; k++)
			{
				if((now + 2) % 3 != 0)
				{
					ans = "2" + ans;
					now += 2;	
				}
				else if ((now + 3) % 3 != 0)
				{
					ans = "3" + ans;
					now += 3;
				}
				else if ((now + 5) % 3 != 0)
				{
					ans = "5" + ans;
					now += 5;
				}	
			}	
			cout << ans << "\n";
		}
	}
}