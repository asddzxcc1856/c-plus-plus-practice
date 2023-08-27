#include <iostream>
#include <cstring>
using namespace std;

int v[500001];

int main()
{
	string str;
	while(cin >> str)
	{
		int now = 500000;
		memset(v,0,sizeof(v));
		for(int i = 0 ; i < str.length() ; i++)
		{
			
			if(str[i] == 'X')
			{
				now = 0;
				v[i] = now;
			}
			else
			{
				v[i] = now;
				now++;
			}
		}	
		now = 500000;
		int ans = 0;
		for(int i = str.length() - 1 ; i >= 0 ; i--)
		{
			if(str[i] == 'X')
			{
				now = 0;
				ans = max(ans,min(v[i],now));
			}
			else
			{
				ans = max(ans,min(v[i],now));
				now++;
			}
		}	
		cout << ans << "\n";
	}	
} 
