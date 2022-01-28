#include <iostream>
#include <set>
#include <vector>
using namespace std;

string str[6],str2[6];
set<char> se[6];
vector<string> s;

int main ()
{
	int t;
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		int num;
		cin >> num;
		for(int i = 0 ; i < 6 ; i++)
		{
			cin >> str[i];
		}
		for(int i = 0 ; i < 6 ; i++)
		{
			cin >> str2[i];
		}
		for(int i = 0 ; i < 5 ; i++)
		{
			se[i].clear();
		}
		for(int i = 0 ; i < 6 ; i++)
		{
			for(int w = 0 ; w < 5 ; w++)
			{
				for(int q = 0 ; q < 6 ; q++)
				{
					if(str[i][w] == str2[q][w])
					{
						se[w].insert(str[i][w]);
					}
				}
			}
		}
		int num2 = 1;
		bool f = true;
		string ans;
		for(set<char>::iterator it1 = se[0].begin() ; it1 != se[0].end() && f ; it1++)
			for(set<char>::iterator it2 = se[1].begin() ; it2 != se[1].end() && f ; it2++)
				for(set<char>::iterator it3 = se[2].begin() ; it3 != se[2].end() && f ; it3++)
					for(set<char>::iterator it4 = se[3].begin() ; it4 != se[3].end() && f ; it4++)
						for(set<char>::iterator it5 = se[4].begin() ; it5 != se[4].end() && f ; it5++)
						{
							if(num2==num)
							{
								f = false;
								ans += *it1;
								ans += *it2;
								ans += *it3;
								ans += *it4;
								ans += *it5;	
							}
							else
								num2++;
						}
		if(f == false)
		{
			cout << ans << "\n";
		}
		else
		{
			
			cout << "NO\n";
		}
	}
}
