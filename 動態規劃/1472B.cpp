#include <iostream> //greedy
using namespace std;

int main ()
{
	int t,n,c[105];
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		cin >> n;
		int x1 = 0,x2 = 0;
		for(int i = 0 ; i < n ; i++)
		{
			int num;
			cin >> num;
			if(num == 1)
				x1++;
			else
				x2++;
		}
		if(x2 % 2 != 0)
		{
			if(x1 >= 2)
			{
				x1 -= 2;
				if(x1 % 2 == 0)
				{
					cout << "YES\n";
				}
				else
				{
					cout << "NO\n";
				}
			}
			else
			{
				cout << "NO\n";
			}
		}
		else
		{
			if(x1 % 2 == 0)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}
