#include <iostream>
using namespace std;

int main ()
{
	int t[26] = {0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
	string str;
	while(getline(cin,str))
	{
		int pre = -1;
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(t[str[i] - 'A'] != 0)
			{
				if(t[str[i] - 'A'] != pre)
				{
					cout << t[str[i] - 'A'];
				}
			}
			pre = t[str[i] - 'A'];
		}
		cout << "\n";
	}
}
