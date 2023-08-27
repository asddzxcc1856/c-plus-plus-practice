#include <iostream>
using namespace std;

struct student{
	int a;
	int b;
	int c;
};

int main ()
{
	int times = 1;
	int n;
	while(cin >> n,n)
	{
		student st[n];
		for(int i = 0 ; i < n ; i++)
		{
			cin >> st[i].a >> st[i].b >> st[i].c;
			st[i].c--;
		}
		int k;
		for(k = 1 ; k <= 10000 ; k++)
		{
			bool aw = true;
			int cnt = 0;
			for(int i = 0 ; i < n ; i++)
			{
				if(st[i].c > (st[i].a - 1))
				{
					aw = false;
				}
				else
				{
					cnt++;
				}
			}
			for(int i = 0 ; i < n ; i++)
			{
				if(((n - cnt) > cnt) || (st[i].c > st[i].a - 1))
					st[i].c = (st[i].c + 1)%(st[i].a + st[i].b);
			}
			if(aw)
			{
				break;
			}
		}
		if(k != 10001)
		{
			cout << "Case " << times++ << ": " << k << "\n"; 
		}
		else
		{
			cout << "Case " << times++ << ": -1\n"; 
		}
		
	}
}
