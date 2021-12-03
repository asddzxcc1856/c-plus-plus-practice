#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int n,n2;
bool isp,isp2;
string s;
int main ()
{
	while(cin >> n)
	{
		if(n == 0 || n == 1)
		{
			cout << n << " is not prime.\n";
		}
		else if(n==2)
		{
			cout << n << " is emirp.\n";
		}
		else
		{
			isp = true;
			for(int i = 2 ; i * i <= n ; i++)
			{
				if(n % i == 0)
				{
					isp = false;
					break;
				}
			}	
			stringstream ss;
			ss << n;
			ss >> s;
			reverse(s.begin(),s.end());
			stringstream ss2(s);
			ss2 >> n2;
			isp2 = true;
			for(int i = 2 ; i * i <= n2 ; i++)
			{
				if(n2 % i == 0)
				{
					isp2 = false;
					break;
				}
			}
			if(isp&&isp2 && n!=n2)
			{
				cout << n << " is emirp.\n";
			}
			else if (isp)
			{
				cout << n << " is prime.\n";
			}
			else
			{
				cout << n << " is not prime.\n";
			}
		}
		
	}
	
    return 0;
}

