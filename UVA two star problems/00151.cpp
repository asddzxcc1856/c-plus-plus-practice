#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	int n;
	while(cin >> n)
	{
		if( n == 0 )
		{
			return 0;
		}
		bool found = false;
		int ans;
		for (int i = 1 ; i <= 500 && found == false; i++)
		{
			vector<int> v;
			for (int j = 1 ; j <= n ; j++)
			{
				v.push_back(j);
			}
			v.erase(v.begin());
			int now = 0;
			while(v.size()>=2)
			{
				now = (now + i - 1)%v.size();
				v.erase(v.begin() + now);
			}
			if(v.front() == 13)
			{
				found = true;
				ans = i;
			}
		}
		cout << ans << "\n";
	}
}
