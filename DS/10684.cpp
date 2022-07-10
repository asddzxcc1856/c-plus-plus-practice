#include <iostream>
using namespace std;

int main ()
{
	int n;
	while(cin >> n)
	{
		if(n == 0)
		{
			return 0;
		}
		int a,sum = 0,maxsum = 0;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> a;
			sum += a;
			if(sum < 0)
			{
				sum = 0;
			}
			if(sum > maxsum)
			{
				maxsum = sum;
			}
		}
		
		if(maxsum > 0)
		{
			cout << "The maximum winning streak is " << maxsum << ".\n";
		}
		else
		{
			cout << "Losing streak.\n";
		}
	}
}