#include <iostream>
#include <list>
using namespace std;

int main ()
{
	string str;
	while(getline(cin,str))
	{
		list<char> ls,ls2;
		bool back = true;
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(str[i] == '[')
			{
				for(auto it = ls2.rbegin() ; it != ls2.rend() ; it++)
					ls.push_front(*it);
				ls2.clear();
				back = false;
			}
			else if (str[i] == ']')
			{
				for(auto it = ls2.rbegin() ; it != ls2.rend() ; it++)
					ls.push_front(*it);
				ls2.clear();
				back = true;
			}
			else
			{
				if(back)
				{
					ls.push_back(str[i]);
				}
				else
				{
					ls2.push_back(str[i]);
				}
			}
		}
		for(auto it = ls2.rbegin() ; it != ls2.rend() ; it++)
			ls.push_front(*it);
		ls2.clear();
		for(list<char>::iterator it = ls.begin() ; it != ls.end() ; it++)
		{
			cout << *it;
		}
		cout << "\n";
	}
	
	
}