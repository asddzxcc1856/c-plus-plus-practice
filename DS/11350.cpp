#include <iostream>
#include <deque>
using namespace std;

deque<pair<long long int,long long int>> d;

int main ()
{
	int n;
	while(cin >> n)
	{
		
		string str;
		for(int k = 1 ; k <= n ; k++)
		{
			cin >> str;
			d.clear();
			pair<long long int,long long int> p;
			p.first = 0;
			p.second = 1;
			d.push_back(p);
			p.first = 1;
			p.second = 1;
			d.push_back(p);
			p.first = 1;
			p.second = 0;
			d.push_back(p);
			p.first = 1;
			p.second = 1;
			int now = 1;
			for(int i = 0 ; i < str.length() ; i++)
			{
				if(str[i] == 'R')
				{
					p.first = d[now].first + d[now + 1].first;
					p.second = d[now].second + d[now + 1].second;
					d.insert(d.begin() + now + 1,p);
					now+=1;
				}
				else
				{
					p.first = d[now].first + d[now - 1].first;
					p.second = d[now].second + d[now - 1].second;
					d.insert(d.begin() + now,p);
				}
				
			}
			cout << p.first << "/" << p.second << "\n";
		}
	
	}
	
	
}