#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int c[150005];
set<int> se; 

int main ()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> c[i]; 
	}
	sort(c,c+n);
	int cnt = 0;
	if(c[0] != 1)
		se.insert(c[0] - 1);
	else
		se.insert(c[0]);
	for(int i = 1 ; i < n ; i++)
	{
		if(se.find(c[i] - 1) != se.end() || c[i] == 1)
		{
			if (se.find(c[i]) != se.end())
			{
				se.insert(c[i] + 1);
			}
			else
			{
				se.insert(c[i]);
			}
		}
		else
		{
			if(c[i] != 1)
				se.insert(c[i] - 1);
			else if (se.find(c[i]) != se.end())
			{
				se.insert(c[i] + 1);
			}
			else
			{
				se.insert(c[i]);
			}	
		}	
	}
	if(n != 0)
		cout << se.size() << "\n";
	else
		cout << 0 << "\n";
}
