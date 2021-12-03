#include <iostream>
using namespace std;

int a,b,i,j,cnt;

int main ()
{
	while(cin >> a >> b)
	{
		if(a == 0 && b == 0)
			return 0;
			
		cnt = 0;
		for (i = a ; i <= b ;i++)
			for (j = 1 ; j * j <= i ; j++)
			{
				if(j*j == i)
				{
					cnt++;
					break;
				}
			}
		cout << cnt << "\n";
	}

    return 0;
}

