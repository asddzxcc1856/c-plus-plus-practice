#include <iostream>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	cin.get();
	for(int k = 0 ; k < n ; k++)
	{
		string str;
		getline(cin,str);
		int fre[26] = {};
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(str[i] >= 'A' && str[i] <= 'Z')
			{
				fre[str[i] - 'A']++;
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				fre[str[i] - 'a']++;
			}
		}
		int maxn = 0;
		for(int i = 0 ; i < 26 ; i++)
		{
			maxn = fre[i] > maxn ? fre[i] : maxn;
		}
		for(int i = 0 ; i < 26 ; i++)
		{
			if(fre[i] == maxn)
			{
				cout << (char)(i + 'a');
			}
		}
		cout << "\n";
	}
}
