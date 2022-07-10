#include <iostream>
using namespace std;

bool operator<(const string & a,const string & b)
{
	for(int i = 0 ; i < a.length() ; i++)
	{
		if(a[i] > b[i])
		{
			return false;
		}
	}
	return true;
}

string operator++(string & str)
{
	str[str.length() - 1] = str[str.length() - 1] == '0' ? '1' :'2';
	for(int i = str.length() - 1 ; i >= 1 ; i--)
	{
		if(str[i] == '2')
		{
			str[i - 1] += ((str[i] - '0')/2);
			str[i] = '0';
		}
	}
	return str;	
}

int main ()
{
	for(string k = "00000000000000000000" ; k < "11111111111111111111" ; ++k)
	{
		cout << k << "\n";
	}
}