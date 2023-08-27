#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main ()
{
	string str1,str2;
	while(getline(cin,str1))
	{
		getline(cin,str2);
		stringstream ss1(str1),ss2(str2);
		
		int num;
		set<int> s1,s2;
		while(ss1 >> num)
		{
			s1.insert(num);
		}
		while(ss2 >> num)
		{
			s2.insert(num);
		}
		bool t1 = true, t2 = true, t3 = true, t4 = true;
		if(s1.size() == s2.size())
		{
			
			for(auto it = s1.begin(),it2 = s2.begin() ; it != s1.end() && it2 != s2.end() ; it++, it2++)
			{
				if(*it != *it2)
				{
					t1 = false;
					break;
				}
			}
		}
		else
		{
			t1 = false;
		}
		for(auto it = s1.begin() ; it != s1.end() ; it++)
		{
			if(s2.find(*it) == s2.end())
			{
				t2 = false;
				break;
			}
		}
		for(auto it = s2.begin() ; it != s2.end() ; it++)
		{
			if(s1.find(*it) == s1.end())
			{
				t3 = false;
				break;
			}
		}
		int cnt = 0;
		for(auto it = s1.begin() ; it != s1.end() ; it++)
		{
			if(s2.find(*it) == s2.end())
			{
				cnt++;
			}
		}
		if(cnt != s1.size())
		{
			t4 = false;
		}
		if(t1)
		{
			cout << "A equals B\n";
		}
		else if (t2)
		{
			cout << "A is a proper subset of B\n";
		}
		else if (t3)
		{
			cout << "B is a proper subset of A\n";
		}
		else if (t4)
		{
			cout << "A and B are disjoint\n";
		}
		else
		{
			cout << "I'm confused!\n";
		}
	}
}