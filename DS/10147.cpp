#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct E{
	double w;
	int start;
	int end;
};

struct P{
	int x,y;
};

int p[755],sum[755];
bool used[755];
P po[755];
vector<E> edge;

bool cmp(E a,E b)
{
	return a.w < b.w;
}

int findp(int n)
{
	while(p[n] != n)
	{
		n = p[n]; 
	}
	return n;
}

int main ()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		int num;
		cin >> num;
		for(int i = 1 ; i <= num ; i++)
		{
			cin >> po[i].x >> po[i].y;
		}
		
		for(int i = 0 ; i < 755 ; i++)
		{
			p[i] = i;
			sum[i] = 0;	
		}
		
		int num2;
		cin >> num2;
		memset(used,false,sizeof(used));
		for(int i = 0 ; i < num2 ; i++)
		{
			int a,b;
			cin >> a >> b;
			
			int pa = findp(a);
			int pb = findp(b);
			if(pa != pb)
			{
				if(sum[pa] >= sum[pb])
				{
					sum[pa] += sum[pb];
					p[pb] = pa;
				}
				else
				{
					sum[pb] += sum[pa];
					p[pa] = pb;
				}
			}
		}
		edge.clear();
		for(int i = 1 ; i <= num ; i++)
		{
			for(int j = i + 1 ; j <= num ; j++)
			{
					E e;
					e.w = (po[i].x - po[j].x) * (po[i].x - po[j].x) + (po[i].y - po[j].y) * (po[i].y - po[j].y);
					e.start = i;
					e.end = j;
					edge.push_back(e);
			}
		}
		bool ok = 0;
		sort(edge.begin(),edge.end(),cmp);
		for(int i = 0 ; i < edge.size() ; i++)
		{
			int a = edge[i].start,b = edge[i].end;
			
			int pa = findp(a);
			int pb = findp(b);
			if(pa != pb)
			{
				if(sum[pa] >= sum[pb])
				{
					sum[pa] += sum[pb];
					p[pb] = pa;
				}
				else
				{
					sum[pb] += sum[pa];
					p[pa] = pb;
				}
				ok = 1;
				cout << a << " " << b << "\n";
			}
		}
		if(ok == 0)
		{
			cout << "No new highways need\n";
		}
		if(k!=t)
		{
			cout << "\n";
		}
	}
	
}