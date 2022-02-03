#include <iostream> //greedy
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		int num;
		cin >> num;
		int maxn = 0,minn = 100,mni,mii;
		for(int i = 1 ; i <= num ; i++)
		{
			int n;
			cin >> n;
			if(n > maxn)
			{
				maxn = n;
				mni = i;
			}
			if(n < minn)
			{
				minn = n;
				mii = i;
			}
		}
		int ans;
		if(mni < mii)
		{
			ans = min(mii,min(num - mni + 1,mni+(num - mii + 1)));
			cout << ans << "\n";
		}
		else
		{
			ans = min(mni,min(num - mii + 1,mii+(num - mni + 1)));
			cout << ans << "\n";
		}
	}
}
