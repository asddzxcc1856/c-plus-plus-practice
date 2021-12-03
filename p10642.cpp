#include <iostream>
using namespace std;

int n;
long long int x1,y1,x2,y2,i,j,ans1,ans2,ans3;

int main ()
{
	cin >> n;
	for (j = 1 ; j <= n ; j++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		
		if(x1+y1 != x2+y2)
		{
			ans1 = y1;
			ans2 = (x2 + y2) - y2 +1;
		}
		else
		{
			ans1 = y1 - y2;
			ans2 = 0;
		}
		ans3 = 0;
		if(x1+y1+2 <= x2+y2)
		{
			for (i = x1 + y1 + 1 ; i <= x2 + y2 - 1 ; i++)
			{
				ans3 += (i+1);
			}	
		}
		
		cout << "Case " << j << ": " << ans1 + ans2 + ans3 << "\n";
	} 

    return 0;
}

