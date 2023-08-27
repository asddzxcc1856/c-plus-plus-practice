#include <iostream>
using namespace std;

int main ()
{
	int fre[52];
	string inp;
	while(getline(cin,inp))
	{
		for(int i = 0 ; i < 52 ; i++)
			fre[i] = 0;
		for(int i = 0 ; i < inp.length() ; i++)
		{
			if(inp[i] >= 'a' && inp[i] <= 'z')
			{
				fre[inp[i] - 'a' + 26]++;
			}
			else if(inp[i] >= 'A' && inp[i] <= 'Z')
			{
				fre[inp[i] - 'A']++;
			}
		}
		int maxfre = 0;
		for(int i = 0 ; i < 52 ; i++)
		{
			if(maxfre < fre[i])
				maxfre = fre[i];
		}
		for(int i = 0 ; i < 52 ; i++)
		{
			if(i < 26 && maxfre == fre[i])
				cout << (char)(i + 'A');
			else if (maxfre == fre[i])
				cout << (char)(i + 'a' - 26);
		}
		cout << " " << maxfre << "\n";
	}
	
} 
