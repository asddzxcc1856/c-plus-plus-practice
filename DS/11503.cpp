#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct edge{
	int w;
	int s;
	int e;	
};

int num[100005],pa[100005];
map<string,int> ma;
vector<edge> v;

bool cmp(edge a,edge b)
{
	return a.w < b.w;
}

int findp(int n)
{
	if(pa[n] != n)
	{
		return findp(pa[n]);
	}
	return n;
}

int main ()
{
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		int n;
		cin >> n;
		int len = 0;
		v.clear();
		ma.clear();
		for(int i = 0 ; i < n ; i++)
		{
			string str1,str2;
			cin >> str1 >> str2;
			if(ma.find(str1) == ma.end())
			{
				ma[str1] = len++; 
			}
			if(ma.find(str2) == ma.end())
			{
				ma[str2] = len++;
			}
			edge E;
			E.w = 1;
			E.s = ma[str1];
			E.e = ma[str2];
			v.push_back(E);
		}
		for(int i = 0 ; i < len ; i++)
		{
			pa[i] = i;
			num[i] = 1;
		}
		for(int i = 0 ; i < v.size() ; i++)
		{
			int a = findp(v[i].s);
			int b = findp(v[i].e);
			if(a != b)
			{
				if(num[a] >= num[b])
				{
					num[a] += num[b];
					pa[b] = pa[a];
					cout << num[a] << "\n";
				}
				else
				{
					num[b] += num[a];
					pa[a] = pa[b];
					cout << num[b] << "\n";
				}
			}
			else
			{
				cout << num[a] << "\n";
			}
		}
	}
}