#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main ()
{
	string str;
	vector<char> v;
	cin >> str;
	for(int i = 0 ; i < str.length() ; i++)
	{
		if(str[i] >= '1' && str[i] <= '3')
		{
			v.push_back(str[i]);
		}
	}
	sort(v.begin(),v.end());
	for(int i = 0 ; i < v.size() ; i++)
	{
		if(i >= 1)
		{
			cout << "+";
		}
		cout << v[i];
	}
	cout << "\n";
}
