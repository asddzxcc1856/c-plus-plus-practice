#include <iostream>
using namespace std;

int main ()
{
	string s;
	while(cin >> s)
	{
		if(s=="0")
			return 0;
		while(s.length() > 1)
		{
			string t;
			int sum = 0;
			for(int i = 0 ; i < s.length() ; i++)
			{
				sum = sum + (s[i] - 48);		
			}
			while(sum!=0)
			{
				t += (sum%10 + 48);
				sum/=10;
			}
			s = t;
		}
		cout << s << "\n"; 
	}

    return 0;
}

