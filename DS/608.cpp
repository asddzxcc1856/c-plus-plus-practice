#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	int w[12];
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		string s1[3],s2[3],a[3];
		cin >> s1[0] >> s2[0] >> a[0];
		cin >> s1[1] >> s2[1] >> a[1];
		cin >> s1[2] >> s2[2] >> a[2];
		
		char ans;
		bool light;
		bool f = true;
		for(int g = 0 ; g < 2 && f ; g++)
		{
			
			for(int q = 0 ; q < 12 && f ; q++)
			{
				memset(w,0,sizeof(w));
				w[q] = (g == 0 ? 1 : -1);
				int cnt = 0;
				for(int i = 0 ; i < 3 && f ; i++)
				{
					int sum1 = 0,sum2 = 0;
					for(int j = 0 ; j < s1[i].length() ; j++)
					{
						sum1 += w[s1[i][j] - 'A'];
					}
					for(int j = 0 ; j < s2[i].length() ; j++)
					{
						sum2 += w[s2[i][j] - 'A'];
					}
					string tmp;
					if(sum1 == sum2)
					{
						tmp = "even";
					}
					else if (sum1 > sum2)
					{
						tmp = "up";
					}
					else
					{
						tmp = "down";
					}
					if(tmp == a[i])
					{
						cnt++;
					}
				}
				if(cnt == 3)
				{
					f = false;
					ans = q + 'A';
					light = (g == 0 ? false : true);
					break;
				}
			}
		}
		
		
		cout << ans << " is the counterfeit coin and it is ";
		((light == true) ? (cout << "light.\n") : ( cout << "heavy.\n"));
	}
}