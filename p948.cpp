#include <iostream>
using namespace std;

int n,num,fib[50] = {0,1};


int main ()
{
	for(int i = 2 ; i < 45 ; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
		
	cin >> n;
	
	for(int w = 0 ; w < n ; w++)
	{
		string str;
		str = "";
		cin >> num;
		int ans = num;
		for(int i = 44 ; i >= 2; i--)
		{
			if(fib[i]<=num)
			{
				num -= fib[i];
				str += "1";
			}
			else if(str.length()>0)
			{
				str += "0";
			}
			
		}
		cout << ans << " = " << str << " (fib)" << "\n";
	}

    return 0;
}

