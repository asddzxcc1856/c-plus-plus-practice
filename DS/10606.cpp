#include <iostream>
using namespace std;

string number;
string number2;
int main ()
{
	while(cin >> number)
	{
		if(number == "0")
			return 0;
		
		int i;
		for(i = number.length() - 1 ; i >= 2 ; i-=2);
		cout << i << "\n";
		if(i == 1)
		{
			number2 = "";
			number2 += '0';	
		}
		else if (i == 0)
		{
			number2 = "";
		}
		number = "0" + number;
		for(int i = 9 ; i >= 1 ; i--)
		{
			string tmp = (char)(i + '0') + number2;
			for(int j = tmp.size() - 1 ; j >= 0 ; j--)
			{
				tmp[j] = ((tmp[j] - '0') * i) + '0';
				cout << tmp[j];
			}
			cout << "\n";
			for(int j = tmp.size() - 1 ; j >= 1 ; j--)
			{
				if(tmp[j] >= (10 + '0'))
				{
					tmp[j - 1] += (tmp[j] - '0')/10;
					tmp[j] = (tmp[j] - '0') % 10 + '0'; 
				}
				cout << tmp[j];
			}
			cout << "\n";
			cout << (int)tmp[0] << "\n";
			if(tmp[0] >= (10 + '0'))
			{
				
				tmp = ((char)((tmp[0] - '0')/10 + '0')) + tmp;
				tmp[1]  = (tmp[1] - '0') % 10 + '0'; 
			}
			cout << tmp[0] << tmp[1] << "\n";
			if(number >= tmp)
			{
				number2 = tmp;
				break;
			}
		}
		for(int i = 0 ; i < number2.length() ; i++)
		{
			cout << number2[i];
		}
		cout << "\n";
		/*
		for(; i < number.length() ; i += 2)
		{
			for(int i = 0 ; i <= 9 ; i++)
			{
				string tmp =  + number2 + (char)(i + '0');
			}
		}*/
	}
}