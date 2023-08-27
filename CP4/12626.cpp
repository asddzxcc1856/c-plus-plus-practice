#include <iostream>
using namespace std;

int main () 
{
	int n;
	cin >> n;
	cin.get();
	for(int k = 0 ; k < n ; k++)
	{
		int have[26] = {};
		string str;
		getline(cin,str);
		for(int i = 0 ; i < str.length() ; i++)
		{
			have[str[i] - 'A']++;
		}	
		string pizza = "MARGARITA";	
		bool ok;
		int ans = 0;
		while(1)
		{
			ok = true;
			for(int i = 0 ; i < pizza.length() ; i++)
			{
				if(have[pizza[i] - 'A'])
				{
					have[pizza[i] - 'A']--;
				}
				else
				{
					ok = false;
					break;	
				}	
			}	
			if(ok)
				ans++;
			else
				break;
		}
		cout << ans << "\n"; 
	}
}
