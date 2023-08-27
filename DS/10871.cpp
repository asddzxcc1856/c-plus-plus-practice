#include <iostream>
using namespace std;

int c[10005];
bool p[500005];

bool isp(int n)
{
	for(int i = 2 ; i * i <= n ; i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main ()
{

	p[0] = false;
	p[1] = false;
	p[2] = true;
	for(int i = 3 ; i < 500005 ; i++)
	{
		p[i] = isp(i);
	}
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		int n;
		cin >> n;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> c[i];
		}
		bool found = false;
		int ans = -1;
		int start,end;
		for(int i = 2 ; i <= n ; i++)
		{
			int sum = 0;
			for(int j = 0 ; j < n ; j++)
			{
				if((j + 1) > i)
				{
					sum -= c[j - i];
				}
				sum += c[j];
				//cout << sum << "\n";
				if((j + 1) >= i && p[sum] == true)
				{
					ans = i;
					start = max(j - i + 1,0);
					end = j;
					found = true;
					break;
				}
				
			}
			if(found == true)
			{
				break;
			}
		}
		if(ans != -1)
		{
			cout << "Shortest primed subsequence is length " << ans << ": ";
			for(int i = start ; i < end ; i++)
			{
				cout << c[i] << " ";
			}
			cout << c[end] << "\n";
		}
		else
		{
			cout << "This sequence is anti-primed.\n";
		}
	}
}