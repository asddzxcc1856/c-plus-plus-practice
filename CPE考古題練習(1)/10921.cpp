#include <iostream>
using namespace std;

int main ()
{
	string str;
	while(getline(cin,str))
	{
		string trans = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string numbers = "22233344455566677778889999"; 
		int capital = 0,hyphen = 0;
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(str[i] >= 'A'  && str[i] <= 'Z')
			{
				cout << numbers[trans.find(str[i])];
				capital++;
			}
			else if (str[i] == '-')
			{
				cout << str[i];
				hyphen++;
			}
			else if (str[i] == '1' || str[i] == '0')
			{
				cout << str[i];
			}
		}
		cout << "\n";
	}	
	
}