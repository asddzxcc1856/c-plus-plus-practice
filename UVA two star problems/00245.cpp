#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
	vector<string> v;
	string str;
	while(getline(cin,str))
	{
		if(str == "0")
		{
			return 0;	
		}	
		string temp;
		for (int i = 0 ; i < str.length() ; i++)
		{
			if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			{
				int j;
				for(j = i ; j < str.length() ; j++)
				{
					if((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z'))
					{
						temp += str[j];
						cout << str[j];
					}
					else
					{
						break;
					}
				}
				i = j - 1;
				v.push_back(temp);
				temp = "";
			}
			else if (str[i] >= '1' && str[i] <= '9')
			{
				int sum = 0;
				int j;
				for(j = i ; j < str.length() ; j++)
				{
					if((str[j] >= '0' && str[j] <= '9'))
					{
						sum = sum * 10 + (str[j]-'0');
					}
					else
					{
						break;
					}
				}
				i = j - 1;
				string t = v.at(v.size() - sum);
				cout << t;
				vector<string>::iterator it = find(v.begin(),v.end(),t);
				v.erase(it);
				v.push_back(t);
			}
			else 
			{
				cout << str[i]; 
			}
		}
		cout << "\n";
	}	
} 
