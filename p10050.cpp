#include <iostream>
#include <set>
using namespace std;

int t,num,cnt,i,j,k,day,p,pa[105],ans;

int main ()
{
	set<int> s;
	cin >> t;
	for( j = 0 ; j < t ; j++ )
	{
		cin >> day; 
		cin >> p;
		ans = 0;
		s.clear();
		for( i = 0 ; i < p ; i++ )
		{
			cin >> pa[i]; 
		}
		for( i = 0 ; i < p ; i++)
		{
			num = pa[i];
			cnt = 0;
			while(num<=day)
			{
				if(s.find(num)!=s.end())
				{
					num+=pa[i];	
					continue;
				}
				else
				{
					s.insert(num);
					if(num != 6 && num != 7 )
					{
						if (num > 7)
						{
							if(((num - 6) % 7 != 0 ) && ((num - 7) % 7 != 0))
								cnt++;
						}
						else
							cnt++;
					}
						
					num+=pa[i];
				}
				
			}
			ans += cnt;
		}
		cout << ans << "\n";
	} 
	
    return 0;
}

