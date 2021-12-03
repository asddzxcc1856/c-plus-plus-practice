#include <iostream>
#include <algorithm>
using namespace std;

int G,n,i,j;

int main ()
{
	while(cin >> n)
	{
		if(n == 0)
			return 0;
			
		G = 0;	
		for(i = 1 ; i < n ; i++)
		{
			for (j = i + 1 ; j <= n ; j++)
			{
				G += __gcd(i,j);
			}
		}
		
		cout << G << "\n"; 
	}
	

    return 0;
}

