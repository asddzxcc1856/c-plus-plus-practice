#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int k = 1 ; k <= n ; k++)
	{
		string str;
		cin >> str;
		vector<int> v(str.length());
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(str[i] == 'B')
			{
				for(int j = i ; j >= max(0,i - 2) ; j-- )
				{
					v[j] = -1;
				}
			}
			if(str[i] == 'S')
			{
				for(int j = min(i + 1,(int)str.length() - 1); j >= max(0,i - 1) ; j--)
				{
					v[j] = -1;
				}
			}
			if(str[i] == 'D')
			{
				v[i] = -1;
			}
		}
		int cnt = 0;
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(v[i] == 0)
			{
				++cnt;
			}
		}
		cout << "Case " << k << ": " << cnt << "\n";
	}
}
