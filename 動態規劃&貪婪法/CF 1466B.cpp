#include <iostream>
#include <set>
using namespace std;

int main ()
{
	int t,num,a;
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		cin >> num;
		set<int> se;
		for(int i = 0 ; i < num ; i++)
		{
			cin >> a;
			if(se.find(a) != se.end())
			{
				se.insert(a + 1);
			}
			else
			{
				se.insert(a);
			}
		}	
		cout << se.size() << "\n";
	}	
} 
