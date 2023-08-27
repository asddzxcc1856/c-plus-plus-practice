#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct point{
	int number;
	int idx;
};


int main ()
{
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		int n,m,number,idx;
		cin >> n >> m;
		int num[10];
		queue<point> q;
		memset(num,0,sizeof(num));
		for(int i = 0 ; i < n ; i++)
		{
			int a;
			cin >> a;
			num[a]++;
			q.push({a,i});

		}
		int start = 9;
		while(num[start] == 0)
		{
			start--;
		}
		int min = 0;
		while(!q.empty())
		{
			point p = q.front();
			if(p.number < start)
			{
				q.pop();
				q.push(p);
			}
			else if (p.number == start)
			{
				q.pop();
				num[start]--;
				while(num[start] == 0)
				{
					start--;
				}
				min++;
				if(p.idx == m)
				{
					break;
				}
			}
			
		}
		
		cout << min << "\n";
	}
}