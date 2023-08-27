#include <iostream>
#include <map>
using namespace std;

int main ()
{
	map<string,int> ma;
	
	int N;
	string str;
	while(cin >> N >> str)
	{
		for(int i = 0 ; i < str.length() - N + 1 ; i++)
		{
			ma[str.substr(i,N)]++;
		}	
		int maxn = 0;
		string ans;
		for(map<string,int>::iterator it = ma.begin() ; it != ma.end() ; it++)
		{
			if(it->second > maxn)
			{
				maxn = it->second;
				ans = it->first;	
			}	
		} 
		cout << ans << "\n";
		ma.clear();
	}	
} 
