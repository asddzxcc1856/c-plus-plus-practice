#include <iostream>
#include <sstream>
#include <set>
#include <vector>
using namespace std;

set<int> v[105];
set<set<int>> se;

int main ()
{
	int w;
	cin >> w;
	string str;
	getline(cin,str);
	getline(cin,str);
	for(int k = 1 ; k <= w ; k++)
	{
		for(int i = 0 ; i < 105 ; i++)
			v[i].clear();
		se.clear();
		int p,t;
		cin >> p >> t;
		int t1,t2;
		getline(cin,str);
		while(getline(cin,str))
		{
			if(str == "")
				break;
			stringstream ss(str);
			while(ss >> t1 >> t2)
				v[t1].insert(t2);
		}
		for(int i = 1 ; i <= p ; i++)
		{
			se.insert(v[i]);
		}
		cout << se.size() << "\n";
		if(k != w)
			cout << "\n";
	}
	
	return 0;
}