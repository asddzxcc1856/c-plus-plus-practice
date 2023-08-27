#include <iostream> // O(NlogM) : N : number of data M : length of number
using namespace std;

long long int cnt(long long int n,long long int p)
{
	if(p == 0)
		return 1;
	else if (p == 1)
		return n;
	else if (p % 2 == 0)
	{
		return (cnt(n,p/2) * cnt(n,p/2))%131071;
	}
	else
	{
		return (cnt(n,p/2) * cnt(n,p/2) * n)%131071;
	}
}

int main ()
{
	ios::sync_with_stdio(false),cin.tie(0);
	char ch;
	string str;
	while(cin >> ch)
	{
		str = "";
		str += ch;
		int num = 0;
		while(cin >> ch)
		{
			if(ch == '1')
			{
				str = "1" + str;
			}
			else if (ch == '0')
			{
				str = "0" + str;
			}
			else if (ch == '#')
				break;
		}
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(str[i] == '1')
			{
			 	num = (num + cnt(2,i))%131071;
			}
		}
		
		if(num == 0)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	
}