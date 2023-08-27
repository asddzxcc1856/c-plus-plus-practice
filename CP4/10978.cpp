#include <iostream>
using namespace std;

int main ()
{
	int n;
	string card[52],run[52];
	while(cin >> n,n)
	{
		string ans[52] = {};
		for(int i = 0 ; i < n ; i++)
		{
			cin >> card[i] >> run[i];
		}	
		int cnt = -1;
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < run[i].length() ; j++)
			{
				++cnt;
				if(cnt == n)
				{
					cnt = 0;
				}
				while(ans[cnt] != "")
				{
					++cnt;
					if(cnt == n)
					{
						cnt = 0;
					}
				} 
				
			}
			ans[cnt] = card[i]; 
		}
		for(int i = 0 ; i < n - 1 ; i++)
		{
			cout << ans[i] << " ";
		}
		cout << ans[n - 1] << "\n";
	}
	return 0;	
} 
