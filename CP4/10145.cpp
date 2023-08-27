#include <iostream>
#include <map>
#include <set>
using namespace std;

map<int,set<int> > it_trans;
map<int,string> it_mode;
set<int> trans;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string str;
		while(cin >> str)
		{
			if(str == "#")
				break;
			else
			{
				int tr,item;
				cin >> tr >> item;
				map<int,set<int> >::iterator it1 = it_trans.find(item);
				map<int,string>::iterator it2 = it_mode.find(item);
				if(trans.find(tr) != trans.end())
				{
					cout << "IGNORED\n";
				}
				else if(it1 != it_trans.end())
				{
					set<int> tmp = it1->second;
					if(tmp.size() == 1)
					{
						if(tmp.find(tr) != tmp.end())
						{
							if(str == "X")
							{
								it2->second = "X";
							}
							cout << "GRANTED\n";
						}
						else if (it2->second == "S" && str == "S")
						{
							if(str == "X")
							{
								it2->second = "X";
							}
							it1->second.insert(tr);
							cout << "GRANTED\n";
						}
						else
						{
							cout << "DENIED\n";
							trans.insert(tr);
						}
					}
					else 
					{
						if (it2->second == "S" && str == "S")
						{
							if(str == "X")
							{
								it2->second = "X";
							}
							cout << "GRANTED\n";
						}
						else
						{
							cout << "DENIED\n";
							trans.insert(tr);
						}
					}
				}
				else
				{
					set<int> s1;
					s1.insert(tr);
					it_trans[item] = s1;
					it_mode[item] = str;
					cout << "GRANTED\n";
				}
			}
		}
		it_trans.clear();
		it_mode.clear();
		trans.clear();
		if(T != 0)
		{
			cout << "\n";
		}
	}
}
