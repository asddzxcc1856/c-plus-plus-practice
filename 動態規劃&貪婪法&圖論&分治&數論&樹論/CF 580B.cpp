#include <iostream>
#include <algorithm>
#define ll long long
#define N (long long int)(1e5 + 5)
using namespace std;

struct s{
	ll money;
	ll factor;
};

bool cmp(s a,s b)
{
	return a.money < b.money;
}

int main ()
{
	ll n,d;
	s m[N];
	cin >> n >> d;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> m[i].money >> m[i].factor;
	}
	sort(m,m+n,cmp);
	ll front,back = 0,sum = 0,maxsum = 0;
	for(front = 0 ; front < n ; front++)
	{
		while(m[front].money - m[back].money >= d)
		{
			sum -= m[back].factor;
			back++;
		}
		sum += m[front].factor;
		maxsum = max(maxsum,sum);
	}
	cout << maxsum << "\n";
} 
