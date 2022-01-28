#include <iostream>
#include <cstring>
using namespace std;

int n,num;

int main ()
{
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> num;
		if(num != 1)
		{
			int c[10];
			memset(c,0,sizeof(c));
			for(int j = 9 ; j >= 2 ; j--)
			{
				while(num % j == 0)
				{
					c[j]++;
					num/=j;
					if(num == 1)
						break;
				}	
			}	
			if(num == 1)
			{
				for(int j = 2 ; j <= 9 ; j++)
				{
					for(int k = 0 ; k < c[j] ; k++)
					{
						cout << j;
					}
				}
				cout << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
		else
		{
			cout << "1\n";
		}
	}	
} 
