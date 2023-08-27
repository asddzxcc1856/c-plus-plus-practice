#include <iostream>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		int n;
		cin >> n;
		int a,sum = 0,maxsum = -2147483648,start = 1,end,len = 0,ans1,ans2;
		for(int i = 1 ; i < n ; i++)
		{
			cin >> a;
			sum += a;
			if(sum < 0)	
			{
				sum = 0;
				start = i + 1;
			}
			if(sum >= maxsum)
			{
				end = i + 1;
				if(sum == maxsum && (end - start) > len)
				{
					len = end - start;
					ans1 = start;
					ans2 = end;
				}
				else if (sum > maxsum)
				{
					maxsum = sum;
					len = end - start;
					ans1 = start;
					ans2 = end;
				}
			}
		}
		if(maxsum > 0)
			cout << "The nicest part of route " << k << " is between stops " << ans1 <<" and " << ans2 << "\n";
		else
			cout << "Route " << k << " has no nice parts\n";
	}
}