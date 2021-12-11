#include <iostream>
using namespace std;

int n,cnt;
string str;

int main ()
{
	while(cin >> n)
	{
		if(n == 0)
			return 0;
		cnt = 0;
		str = "";
		while(n)
		{
			string temp;
			temp += ((n%2)+'0');
			str = temp + str;
			cnt = n%2 + cnt;
			n/=2;
		}
		cout << "The parity of " << str << " is " << cnt << " (mod 2).\n";
	}

    return 0;
}

