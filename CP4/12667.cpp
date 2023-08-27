#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	int n,t,m;
	int p[13][101];
	int ans[13];
	int time[13];
	while(cin >> n >> t >> m)
	{
		memset(p,0,sizeof(p));
		memset(ans,0,sizeof(ans));
		for(int i = 0 ; i < m ; i++)
		{
			int a,b;
			string c,d;
			cin >> a >> b >> c >> d;
			if(d == "Yes")
			{
				if(p[c[0] - 'A' + 1][b] == 0)
				{
					p[c[0] - 'A' + 1][b] = 1;		
					ans[c[0] - 'A' + 1] = b;	
					time[c[0] - 'A' + 1] = a;
				}	
			} 
		}
		for(int i = 1 ; i <= n ; i++)
		{
			if(ans[i] != 0)
				cout << (char)(i + 'A' - 1) << " " << time[i] << " " << ans[i] << "\n";
			else
				cout << (char)(i + 'A' - 1) << " - -\n";
		}
	}
}
