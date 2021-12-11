#include <iostream>
using namespace std;

string str;
int num;

int main ()
{
	while(cin >> str)
	{
		if (str == "0")
		{
			return 0;
		}
		num = str[0] - '0';
		
		for (int i = 1 ; i < str.length() ; i++)
		{
			num = (num*10 + (str[i]-'0'))%11;
		}
		if(num==0)
		{
			cout << str << " is a multiple of 11.\n";
		}
		else
		{
			cout << str << " is not a multiple of 11.\n";
		}
	}

    return 0;
}

