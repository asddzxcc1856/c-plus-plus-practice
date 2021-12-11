#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	string s1,s2;
	int times;
	int n1[26];
	int n2[26];
	while(getline(cin,s1))
	{
		getline(cin,s2);
		memset(n1,0,sizeof(n1));
		memset(n2,0,sizeof(n2));
		for(int i = 0 ; i < s1.length() ; i++)
		{
			n1[s1[i] - 'a']++;
		}
		for(int i = 0 ; i < s2.length() ; i++)
		{
			n2[s2[i] - 'a']++;
		}
		for(int i = 0 ; i < 26 ; i++)
		{
			times = min(n1[i],n2[i]);
			for(int j = 0 ; j < times ; j++)
			{
				cout << (char)(i + 'a');
			}
		}
		cout << "\n";
	}
	
    return 0;
}

