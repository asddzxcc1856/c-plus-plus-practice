#include <iostream>
#include <set>
using namespace std;

int main ()
{
	int n,r;
	while(cin >> n >> r)
	{
		set<int> se;
		for(int i = 1 ; i <= n ; i++)
		{
			se.insert(i);
		}
		for(int i = 0 ; i < r ; i++)
		{
			int tmp;
			cin >> tmp;
			se.erase(tmp);
		}
		if(se.size() == 0)
		{
			cout << "*";
		}
		else
		{
			for(auto it = se.begin() ; it != se.end() ; it++)
			{
				cout << *it << " ";
			}
		} 
		
		cout << "\n";
	}
}