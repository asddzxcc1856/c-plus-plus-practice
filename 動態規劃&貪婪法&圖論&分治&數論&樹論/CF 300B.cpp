#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;



struct s{
	int number;
	int idx;
};

int p[50];
s num[50];
s num2[50];
bool vis[50];

int findp(int now)
{
	while(p[now] != now)
	{
		now = p[now];
	}
	return now;
}

bool cmp(s a,s b)
{
	return a.number > b.number;
}

int main ()
{
	bool ok = true;
	int n,m;
	cin >> n >> m;
	num[0].number = -100;
	num[0].idx = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		num[i].number = 1;
		num[i].idx = i;
		p[i] = i;
	}
	for(int i = 0 ; i < m ; i++)
	{
		int a,b;
		cin >> a >> b;
		int pa = findp(a); 
		int pb = findp(b);
		if(pa != pb)
		{
			if(num[pa].number > num[pb].number)
			{
				p[pb] = p[pa];
				num[pa].number += num[pb].number;
			}
			else
			{
				p[pa] = p[pb];
				num[pb].number += num[pa].number;
			}
		}
	}
	for(int i = 0 ; i <= n ; i++)
	{
		num2[i] = num[i];
	}
	sort(num2,num2 + n + 1,cmp);
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			
			int a = num2[i].idx,b = num2[j].idx;
			 
			int pa = findp(a); 
			int pb = findp(b);
			
			if( a == b || num[pa].number + num[pb].number > 3)
			{
				continue;
			}
			if(pa != pb)
			{
				//cout << " " << a << " " << b << " " << pa << " " << pb << "\n";
				if(num[pa].number > num[pb].number)
			{
				p[pb] = p[pa];
				num[pa].number += num[pb].number;
			}
			else
			{
				p[pa] = p[pb];
				num[pb].number += num[pa].number;
			}
			}	
		}
	
	}
	int cnt = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		//cout << " " << num[i].idx << " " << p[num[i].idx] << " " << num[i].number << "\n";
		if(num[i].number > 3)
			ok = false;
		else if (num[i].number == 3)
		{
			cnt++;
		}
	}
	if(ok && n / 3 == cnt)
	{
		int team = n / 3;
		for(int k = 0 ; k <= n ; k++)
		{
			if(num[k].number == 3)
			{
				for(int j = n ; j >= 0 ; j--)
				{
					if(k == p[j])
					{
						cout << j << " ";
					}
				}
				cout << "\n";
			} 
		}
	}
	else
	{
		cout << "-1\n";
	}
	

}
