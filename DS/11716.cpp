#include <iostream>
using namespace std;

int t,n;

int main ()
{
	while(cin >> t)
	{
		string str;
		getline(cin,str);
		for(int k = 1 ; k <= t ; k++)
		{
			getline(cin,str);
			bool ok = false;
			int idx;
			for(int i = 1 ; i * i <= 10000 ; i++)
			{
				if(str.length() == i * i)
				{
					ok = true;
					idx = i;
					break;
				}
			}
			if(ok == false)
			{
				cout << "INVALID\n";
				continue;
			}
			for(int i = 0 ; i < idx ; i++)
			{
				for(int j = i ; j < str.length() ; j += idx)
				{
					cout << str[j];
				}
			}
			cout << "\n";
		}
	}
}