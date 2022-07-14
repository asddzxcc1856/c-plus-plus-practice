#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main ()
{
	int p,c,times = 1;
	while(cin >> p >> c)
	{
		if(p == 0 && c == 0)
		{
			return 0;
		}
		deque<int> d;
		for(int i = 1 ; i <= min(p,1000000) ; i++)
		{
			d.push_back(i);
		}
		cout << "Case " << times++ << ":\n"; 
		for(int i = 0 ; i < c ; i++)
		{
			char n;
			cin >> n;
			if(n == 'N')
			{
				cout << d.front() << "\n";
				d.push_back(d.front());
				d.pop_front();
			}
			else if (n == 'E')
			{
				int a;
				cin >> a;
				auto it = find(d.begin(),d.end(),a);
				if(it != d.end())
					d.erase(it);
				d.push_front(a);
			} 
		}
	}
}