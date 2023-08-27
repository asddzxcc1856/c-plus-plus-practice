#include <iostream>
using namespace std;

int main ()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int n;
	cin >> n;
	for(int k = 1 ; k <= n ; k++)
	{
		string str;
		int S = 0;
		cin >> str;
		unsigned int num;
		if(str.length() % 2)
		{
			num = str[str.length() / 2] - 48;
			for(int i = str.length() / 2 - 1 ; i >= 0 ; i--)
			{
				if(str[i] >= str[str.length() - i - 1])
				{
					num = (num * 2 + (str[i] - 48))%1000000007;
					num = (num * 2 + (str[str.length() - i - 1] - 48))%1000000007;
				}
				else
				{
					num = (num * 2 + (str[str.length() - i - 1] - 48))%1000000007;
					num = (num * 2 + (str[i] - 48))%1000000007;	
				}	
				
			}
		}
		else
		{
			num = 0;
			for(int i = str.length() / 2 ; i > 0 ; i--)
			{
				if(str[i - 1] >= str[str.length() - i])
				{
					num = (num * 2 + (str[i - 1] - 48))%1000000007;
					num = (num * 2 + (str[str.length() - i] - 48))%1000000007;
				}
				else
				{
					num = (num * 2 + (str[str.length() - i] - 48))%1000000007;
					num = (num * 2 + (str[i - 1] - 48))%1000000007;	
				}	
				
			}
		}
		cout << "Case #" << k << ": " << num << "\n";
	}
}
