#include <iostream>
#include <map>
using namespace std;

map<int,pair<int,int>> ma;
int num[6];
int dx[6] = {-1,0,1,1,0,-1};
int dy[6] = {0,-1,-1,0,1,1};
int main ()
{
	pair<int,int> p;
	p.first = 0;
	p.second = 0;
	ma[1] = p;
	p.first = 0;
	p.second = 1;
	ma[2] = p;
	
	for(int i = 0 ; i < 6 ; i++)
	{
		num[i] = 1;
	}
	num[4] = 2;
	int now = 3;
	while(now <= 100000)
	{
		for(int j = 0 ; j < 6 ; j++)
		{
			for(int k = 0 ; k < num[j] ; k++)
			{
				p.first = p.first + dx[j];
				p.second = p.second + dy[j];
				ma[now] = p;
				now++;
				if(now > 100000)
					break;
			}
			if(now > 100000)
				break;
			num[j]++;
		}
	}
	int x;
	while(cin >> x)
	{
		cout << ma[x].first << " " << ma[x].second << "\n";
	}
	return 0;
}