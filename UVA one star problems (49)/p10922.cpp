#include <iostream>
#include <sstream>
using namespace std;

string str,str2;
int num,num2,cnt;

int main ()
{
	while(cin >> str)
	{
		if(str == "0")
			return 0;
		num = str[0] - '0';
		for(int i = 1 ; i < str.length() ; i++)
		{
			num = (num * 10 + (str[i] - '0')) % 9;
		}
		num%=9;
		if(num == 0)
		{
			str2 = str;
			cnt = 0;
			num2 = 0;
			for(int i = 0 ; i < str2.length() ; i++)
			{
				num2 += str2[i] - '0';
			}	
			while(num2>0)
			{
				cout << num2 << "\n"; 
				num2 = 0; 
				for(int i = 0 ; i < str2.length() ; i++)
				{
					num2 += str2[i] - '0';
				}	
				if(num % 9 == 0)
					cnt++;
				else
					break;
				stringstream ss;
				ss << num2;
				ss >> str2;
			}
			cout << str << " is a multiple of 9";
			if(cnt>0)
			{
				cout << " and has 9-degree " << cnt;	
			}
			cout << ".\n";
		}
		else
		{
			cout << str << " is not a multiple of 9.\n";
		}
		
	}

    return 0;
}

