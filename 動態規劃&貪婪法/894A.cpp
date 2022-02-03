#include <iostream>
using namespace std;

int main ()
{
	string str;
	cin >> str;
	int len = str.length(),ans = 0;
	for(int i = 0; i < len - 2; i++)
	{
		for(int j = i + 1 ; j < len - 1; j++)
		{
			for(int k = j + 1 ; k < len ; k++)
			{
				if(str[i] == 'Q' && str[j] == 'A' && str[k] == 'Q')
				{
					ans++;
				}
			}
		}
	}
	cout << ans << "\n";
} 
